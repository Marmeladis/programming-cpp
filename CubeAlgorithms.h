#pragma once
#ifndef LAB4_CUBEALGORITHMS_H
#define LAB4_CUBEALGORITHMS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cstdlib>

class CubicRubica {
public:
	CubicRubica() = default;
	~CubicRubica() = default;

	CubicRubica& operator=(CubicRubica& other)
	{
		for (int i = 0; i < 9; i++)
		{
			this->white[i] = other.white[i];
			this->red[i] = other.red[i];
			this->blue[i] = other.blue[i];
			this->green[i] = other.green[i];
			this->orange[i] = other.orange[i];
			this->yellow[i] = other.yellow[i];
		}
		return *this;
	}

	void display(char face[9]) const;
	void clockwise_rotate(char choice);
	void count_colors(char value);
	bool is_assembled();

	void read();
	void read_from_file(std::string text);
	void display_all_cube() const;
	void random();
	void base();
	void write_to_file(std::string text);

	friend class Solver;
	class Solver {};

private:
	void swap(char& a, char& b);
	void rotate_clock(char choice);

	char white[9];
	char red[9];
	char orange[9];
	char blue[9];
	char green[9];
	char yellow[9];

	short White = 0, Red = 0, Orange = 0, Blue = 0, Green = 0, Yellow = 0;
};

class Solver : private CubicRubica {
public:
	Solver(const CubicRubica& cube)
	{
		for (int i = 0; i < 9; i++)
		{
			SolverCube.white[i] = cube.white[i];
			SolverCube.red[i] = cube.red[i];
			SolverCube.blue[i] = cube.blue[i];
			SolverCube.green[i] = cube.green[i];
			SolverCube.orange[i] = cube.orange[i];
			SolverCube.yellow[i] = cube.yellow[i];
		}
	}

	void white_bottom(char q);
	void right_alg(char a, char c);
	void white_right(char q);
	void left_alg(char a, char c);
	void white_left(char q);
	void top_alg(char a, char b, char c);
	void white_top(char q);
	void inv_alg(char a, char b, char c);
	void white_bottom_inverted(char q);

	void solve_white_cross();
	void white_corners_alg_left();
	void white_corners_alg_right();
	void solve_white_corners();
	void middle_place_left_alg(char left, char center);
	void middle_place_right_alg(char center, char right);
	void solve_middle_layer();
	void yellow_cross_algorithm();
	void solve_yellow_cross();
	void yellow_corners_algorithm();
	void solve_yellow_corners();
	void yellow_corner_orientation_algorithm();
	void yellow_corner_orientation();
	void yellow_edges_colour_arrangement_right();
	void yellow_edges_colour_arrangement_left();
	void yellow_edges_colour_arrangement();

public:
	CubicRubica SolverCube;
	void solve();
	bool is_it_full();
};

#endif;