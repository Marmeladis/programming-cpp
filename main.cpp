#include "CubeAlgorithms.h"
#include "CubeException.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

void commands()
{
	std::cout << "\x1b[31m" << "Menu:\n" << "\x1b[0m";
	std::cout << "1) Make a Cube base\n";
	std::cout << "2) Read Cube from file\n";
	std::cout << "3) Enter the Cube manually\n";
	std::cout << "4) Show all Cube\n";
	std::cout << "5) Write Cube to file\n";
	std::cout << "6) Shuffle Cube\n";
	std::cout << "7) Solve Cube\n";
	std::cout << "8) Is the Cube assembled?\n";
	std::cout << "9) Make rotate\n";
	std::cout << "0) Close menu\n";
	std::cout << "\x1b[33m" << "\nCommand: " << "\x1b[0m";
}

void menu_of_rotate()
{
	std::cout << "You can rotate your cube only clockwyse but you can choose faced: \n";
	std::cout << "w - white\n";
	std::cout << "r - red\n";
	std::cout << "b - blue\n";
	std::cout << "g - green\n";
	std::cout << "o - orange\n";
	std::cout << "y - yellow\n";
	std::cout << "Enter the faced: ";
}

void console_interface(CubicRubica& cube)
{
	int cmd;

	while (true) {
		commands();
		std::string text = "";
		char value;
		std::cin >> cmd;
		std::cout << "\x1b[32m" << "Answear...\n" << "\x1b[0m";
		switch (cmd) {
		case 0:
		{
			return;
		}
		case 1:
		{
			cube.base();
			break;
		}
		case 2:
		{
			std::cout << "\nEnter filename: ";
			std::cin >> text;
			cube.read_from_file(text);
			break;
		}
		case 3:
		{
			cube.read();
			break;
		}
		case 4:
		{
			cube.display_all_cube();
			break;
		}
		case 5:
		{
			text = "";
			std::cout << "\nEnter filename: ";
			std::cin >> text;
			cube.write_to_file(text);
			break;
		}
		case 6:
		{
			cube.random();
			break;
		}
		case 7:
		{
			Solver s(cube);
			s.solve();
			cube = s.SolverCube;
			break;
		}
		case 8:
		{
			std::cout << (cube.is_assembled() ? "Yes\n" : "No\n");
			break;
		}
		case 9:
		{
			menu_of_rotate();
			std::cin >> value;
			cube.clockwise_rotate(value);
			break;
		}
		default:
		{
			std::cout << "Enter normal command\n";
			break;
		}
		}
	}
}

int main()
{
	CubicRubica Cubic;
	console_interface(Cubic);
	return 0;
}