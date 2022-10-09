#include "CubeAlgorithms.h"
#include "CubeException.h"

void CubicRubica::count_colors(char value) {
	switch (value) {
	case 'w': {
		if (White < 9) {
			White++;
		}
		else if (White >= 9) {
			throw CountColorsException();
		}
		break;
	}
	case 'r': {
		if (Red < 9) {
			Red++;
		}
		else if (Red >= 9) {
			throw CountColorsException();
		}
		break;
	}
	case 'o': {
		if (Orange < 9) {
			Orange++;
		}
		else if (Orange >= 9) {
			throw CountColorsException();
		}
		break;
	}
	case 'b': {
		if (Blue < 9) {
			Blue++;
		}
		else if (Blue >= 9) {
			throw CountColorsException();
		}
		break;
	}
	case 'g': {
		if (Green < 9) {
			Green++;
		}
		else if (Green >= 9) {
			throw CountColorsException();
		}
		break;
	}
	case 'y': {
		if (Yellow < 9) {
			Yellow++;
		}
		else if (Yellow >= 9) {
			throw CountColorsException();
		}
		break;
	}

	default: throw ColorsException();
	}
}

void CubicRubica::read() {
	std::cout << "________________________| RUBIK'S CUBE SOLVER |________________________" << std::endl;
	std::cout << "Input........." << std::endl;
	std::cout << "White Side : ";
	for (int i = 0; i < 9; ++i)
	{
		std::cin >> white[i];
		count_colors(white[i]);
		if (white[i] != 'w' && i == 8) {
			throw CentersException();
		}
	}
	std::cout << "Red Side : ";
	for (int i = 0; i < 9; ++i)
	{
		std::cin >> red[i];
		count_colors(red[i]);
		if (red[i] != 'r' && i == 8) {

			throw CentersException();
		}
	}
	std::cout << "Orange Side : ";
	for (int i = 0; i < 9; ++i)
	{
		std::cin >> orange[i];
		count_colors(orange[i]);
		if (orange[i] != 'o' && i == 8) {
			throw CentersException();
		}
	}
	std::cout << "Blue Side : ";
	for (int i = 0; i < 9; ++i)
	{
		std::cin >> blue[i];
		count_colors(blue[i]);
		if (blue[i] != 'b' && i == 8) {
			throw CentersException();
		}
	}
	std::cout << "Green Side : ";
	for (int i = 0; i < 9; ++i)
	{
		std::cin >> green[i];
		count_colors(green[i]);
		if (green[i] != 'g' && i == 8) {
			throw CentersException();
		}
	}
	std::cout << "Yellow Side : ";
	for (int i = 0; i < 9; ++i)
	{
		std::cin >> yellow[i];
		count_colors(yellow[i]);
		if (yellow[i] != 'y' && i == 8) {
			throw CentersException();
		}
	}
}

void CubicRubica::read_from_file(std::string text) {
	std::cout << "________________________| RUBIK'S CUBE SOLVER |________________________" << std::endl;
	std::cout << "Input........." << std::endl;
	std::ifstream in(text);
	for (int i = 0; i < 9; ++i)
	{
		in >> white[i];
		count_colors(white[i]);
		if (white[i] != 'w' && i == 8) {
			throw CentersException();
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		in >> red[i];
		count_colors(red[i]);
		if (red[i] != 'r' && i == 8) {

			throw CentersException();
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		in >> orange[i];
		count_colors(orange[i]);
		if (orange[i] != 'o' && i == 8) {
			throw CentersException();
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		in >> blue[i];
		count_colors(blue[i]);
		if (blue[i] != 'b' && i == 8) {
			throw CentersException();
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		in >> green[i];
		count_colors(green[i]);
		if (green[i] != 'g' && i == 8) {
			throw CentersException();
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		in >> yellow[i];
		count_colors(yellow[i]);
		if (yellow[i] != 'y' && i == 8) {
			throw CentersException();
		}
	}
}

void CubicRubica::display(char face[9]) const
{
	for (int i = 0; i < 9; i++)
	{
		std::cout << face[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

void CubicRubica::display_all_cube() const {
	std::cout << std::endl;
	// up
	std::cout << std::setw(15) << " " << white[5] << " " << white[6] << " " << white[7] << std::endl;
	std::cout << std::setw(15) << " " << white[4] << " " << white[8] << " " << white[0] << std::endl;
	std::cout << std::setw(15) << " " << white[3] << " " << white[2] << " " << white[1] << std::endl;
	std::cout << std::endl;

	// center
	std::cout << std::setw(3) << " " << green[6] << " " << green[7] << " " << green[0] << std::setw(4) << " " <<
		std::setw(3) << " " << red[6] << " " << red[6] << " " << red[0] << std::setw(4) << " " <<
		std::setw(3) << " " << blue[6] << " " << blue[7] << " " << blue[0] << std::setw(4) << " " <<
		std::setw(3) << " " << orange[6] << " " << orange[7] << " " << orange[0] << std::setw(4) << std::endl;
	std::cout << std::setw(3) << " " << green[5] << " " << green[8] << " " << green[1] << std::setw(4) << " " <<
		std::setw(3) << " " << red[5] << " " << red[8] << " " << red[1] << std::setw(4) << " " <<
		std::setw(3) << " " << blue[5] << " " << blue[8] << " " << blue[1] << std::setw(4) << " " <<
		std::setw(3) << " " << orange[5] << " " << orange[8] << " " << orange[1] << std::setw(4) << std::endl;
	std::cout << std::setw(3) << " " << green[4] << " " << green[3] << " " << green[2] << std::setw(4) << " " <<
		std::setw(3) << " " << red[4] << " " << red[3] << " " << red[2] << std::setw(4) << " " <<
		std::setw(3) << " " << blue[4] << " " << blue[3] << " " << blue[2] << std::setw(4) << " " <<
		std::setw(3) << " " << orange[4] << " " << orange[3] << " " << orange[2] << std::setw(4) << std::endl;
	std::cout << std::endl;

	//down
	std::cout << std::setw(15) << " " << yellow[3] << " " << yellow[2] << " " << yellow[1] << std::endl;
	std::cout << std::setw(15) << " " << yellow[4] << " " << yellow[8] << " " << yellow[0] << std::endl;
	std::cout << std::setw(15) << " " << yellow[5] << " " << yellow[6] << " " << yellow[7] << std::endl;
}

void CubicRubica::write_to_file(std::string text) {
	std::ofstream out(text);
	for (int i = 0; i < 9; i++)
	{
		out << white[i] << " ";
	}
	out << std::endl;
	for (int i = 0; i < 9; i++)
	{
		out << red[i] << " ";
	}
	out << std::endl;
	for (int i = 0; i < 9; i++)
	{
		out << orange[i] << " ";
	}
	out << std::endl;
	for (int i = 0; i < 9; i++)
	{
		out << blue[i] << " ";
	}
	out << std::endl;
	for (int i = 0; i < 9; i++)
	{
		out << green[i] << " ";
	}
	out << std::endl;
	for (int i = 0; i < 9; i++)
	{
		out << yellow[i] << " ";
	}
}


void CubicRubica::swap(char& a, char& b)
{
	char t = a;
	a = b;
	b = t;
}

std::ofstream out("rubikscubecommands.out");

void CubicRubica::rotate_clock(char choice)
{
	if (choice == 'w')
	{
		out << "White" << std::endl;
		swap(white[7], white[3]);
		swap(white[6], white[4]);
		swap(white[0], white[2]);
		swap(white[7], white[5]);
		swap(white[0], white[4]);
		swap(white[1], white[3]);
		//-------------------------
		swap(blue[0], orange[0]);
		swap(blue[7], orange[7]);
		swap(blue[6], orange[6]);
		swap(orange[6], green[6]);
		swap(orange[7], green[7]);
		swap(orange[0], green[0]);
		swap(green[6], red[6]);
		swap(green[7], red[7]);
		swap(green[0], red[0]);
	}
	//-------------------------
	else if (choice == 'r')
	{
		out << "Red" << std::endl;
		swap(red[0], red[4]);
		swap(red[7], red[5]);
		swap(red[1], red[3]);
		swap(red[0], red[6]);
		swap(red[1], red[5]);
		swap(red[2], red[4]);
		//-------------------------
		swap(blue[6], white[3]);
		swap(blue[5], white[2]);
		swap(blue[4], white[1]);
		swap(white[1], green[0]);
		swap(white[2], green[1]);
		swap(white[3], green[2]);
		swap(green[0], yellow[3]);
		swap(green[1], yellow[2]);
		swap(green[2], yellow[1]);
		//--------------------------
	}
	//-----------------------------------
	else if (choice == 'y')
	{
		out << "Yellow" << std::endl;
		swap(yellow[1], yellow[5]);
		swap(yellow[2], yellow[4]);
		swap(yellow[0], yellow[6]);
		swap(yellow[1], yellow[3]);
		swap(yellow[0], yellow[4]);
		swap(yellow[7], yellow[5]);
		//--------------------------
		swap(blue[4], red[4]);
		swap(blue[3], red[3]);
		swap(blue[2], red[2]);
		swap(red[2], green[2]);
		swap(red[3], green[3]);
		swap(red[4], green[4]);
		swap(green[4], orange[4]);
		swap(green[3], orange[3]);
		swap(green[2], orange[2]);
		//--------------------------
	}
	//-------------------------------------
	else if (choice == 'o')
	{
		out << "Orange" << std::endl;
		swap(orange[4], orange[0]);
		swap(orange[3], orange[1]);
		swap(orange[5], orange[7]);
		swap(orange[4], orange[2]);
		swap(orange[5], orange[1]);
		swap(orange[6], orange[0]);
		//--------------------------
		swap(blue[2], yellow[5]);
		swap(blue[1], yellow[6]);
		swap(blue[0], yellow[7]);
		swap(yellow[5], green[6]);
		swap(yellow[6], green[5]);
		swap(yellow[7], green[4]);
		swap(green[6], white[7]);
		swap(green[5], white[6]);
		swap(green[4], white[5]);
		//--------------------------
	}
	//-------------------------------------
	else if (choice == 'g')
	{
		out << "Green" << std::endl;
		swap(green[6], green[2]);
		swap(green[5], green[3]);
		swap(green[7], green[1]);
		swap(green[4], green[6]);
		swap(green[7], green[3]);
		swap(green[0], green[2]);
		//--------------------------
		swap(white[5], orange[2]);
		swap(white[4], orange[1]);
		swap(white[3], orange[0]);
		swap(yellow[3], orange[2]);
		swap(yellow[4], orange[1]);
		swap(yellow[5], orange[0]);
		swap(yellow[3], red[6]);
		swap(yellow[4], red[5]);
		swap(yellow[5], red[4]);
		//--------------------------
	}
	//-------------------------------------------
	else if (choice == 'b')
	{
		out << "Blue" << std::endl;
		swap(blue[1], blue[7]);
		swap(blue[2], blue[6]);
		swap(blue[5], blue[3]);
		swap(blue[2], blue[0]);
		swap(blue[7], blue[3]);
		swap(blue[6], blue[4]);
		//--------------------------
		swap(yellow[1], orange[4]);
		swap(yellow[0], orange[5]);
		swap(yellow[7], orange[6]);
		swap(white[7], orange[4]);
		swap(white[0], orange[5]);
		swap(white[1], orange[6]);
		swap(white[7], red[0]);
		swap(white[0], red[1]);
		swap(white[1], red[2]);
		//--------------------------
	}
}

void Solver::white_bottom(char q)
{
	if ((SolverCube.yellow[0] == 'w' && SolverCube.blue[3] == q) || (SolverCube.yellow[2] == 'w' && SolverCube.red[3] == q) || (SolverCube.yellow[4] == 'w' && SolverCube.green[3] == q) || (SolverCube.yellow[6] == 'w' && SolverCube.orange[3] == q))
	{
		if (q == 'b')
		{
			while (SolverCube.blue[3] != q || SolverCube.yellow[0] != 'w')
			{
				SolverCube.rotate_clock('y');
			}
		}
		if (q == 'r')
		{
			while (SolverCube.red[3] != q || SolverCube.yellow[2] != 'w')
			{
				SolverCube.rotate_clock('y');
			}
			if (q != 'b')
			{
				while (SolverCube.white[0] != 'w' && SolverCube.blue[7] != 'b')
				{
					SolverCube.rotate_clock('w');
				}
			}
		}
		if (q == 'g')
		{
			while (SolverCube.green[3] != q || SolverCube.yellow[4] != 'w')
			{
				SolverCube.rotate_clock('y');
			}
			if (q != 'b')
			{
				while (SolverCube.white[0] != 'w' && SolverCube.blue[7] != 'b')
				{
					SolverCube.rotate_clock('w');
				}
			}
		}
		if (q == 'o')
		{
			while (SolverCube.orange[3] != q || SolverCube.yellow[6] != 'w')
			{
				SolverCube.rotate_clock('y');
			}
			if (q != 'b')
			{
				while (SolverCube.white[0] != 'w' && SolverCube.blue[7] != 'b')
				{
					SolverCube.rotate_clock('w');
				}
			}
		}
		SolverCube.rotate_clock(q); SolverCube.rotate_clock(q);
	}
}

void Solver::right_alg(char a, char c)
{
	SolverCube.rotate_clock(a); SolverCube.rotate_clock(a); SolverCube.rotate_clock(a);
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock(a); white_bottom(c);
}

void Solver::white_right(char q)
{
	if (SolverCube.blue[1] == 'w' || SolverCube.red[1] == 'w' || green[1] == 'w' || SolverCube.orange[1] == 'w')
	{
		if (SolverCube.blue[5] == q && SolverCube.red[1] == 'w')
		{
			right_alg('b', q);
		}
		if (SolverCube.red[5] == q && SolverCube.green[1] == 'w')
		{
			right_alg('r', q);
		}
		if (SolverCube.green[5] == q && SolverCube.orange[1] == 'w')
		{
			right_alg('g', q);
		}
		if (SolverCube.orange[5] == q && SolverCube.blue[1] == 'w')
		{
			right_alg('o', q);
		}
	}
}

void Solver::left_alg(char a, char c)
{
	SolverCube.rotate_clock(a); SolverCube.rotate_clock('y'); SolverCube.rotate_clock(a);
	SolverCube.rotate_clock(a); SolverCube.rotate_clock(a); white_bottom(c);
}
void Solver::white_left(char q)
{
	if (SolverCube.blue[5] == 'w' || SolverCube.red[5] == 'w' || SolverCube.green[5] == 'w' || SolverCube.orange[5] == 'w')
	{
		if (SolverCube.blue[5] == 'w' && SolverCube.red[1] == q)
		{
			left_alg('r', q);
		}
		if (SolverCube.red[5] == 'w' && SolverCube.green[1] == q)
		{
			left_alg('g', q);
		}
		if (SolverCube.green[5] == 'w' && SolverCube.orange[1] == q)
		{
			left_alg('o', q);
		}
		if (SolverCube.orange[5] == 'w' && SolverCube.blue[1] == q)
		{
			left_alg('b', q);
		}
	}
}

void Solver::top_alg(char a, char b, char c)
{
	SolverCube.rotate_clock(a); SolverCube.rotate_clock(a); SolverCube.rotate_clock(a);
	SolverCube.rotate_clock('w'); SolverCube.rotate_clock(b); SolverCube.rotate_clock('w');
	SolverCube.rotate_clock('w'); SolverCube.rotate_clock('w'); white_bottom(c);
}

void Solver::white_top(char q)
{
	if (SolverCube.blue[7] == 'w' && SolverCube.white[0] == q)
	{
		top_alg('b', 'r', q);
	}
	if (SolverCube.red[7] == 'w' && SolverCube.white[2] == q)
	{
		top_alg('r', 'g', q);
	}
	if (SolverCube.green[7] == 'w' && SolverCube.white[4] == q)
	{
		top_alg('g', 'o', q);
	}
	if (SolverCube.orange[7] == 'w' && SolverCube.white[6] == q)
	{
		top_alg('o', 'b', q);
	}
}

void Solver::inv_alg(char a, char b, char c)
{
	SolverCube.rotate_clock(a); SolverCube.rotate_clock(b); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock(b);
	SolverCube.rotate_clock(b); SolverCube.rotate_clock(b); SolverCube.rotate_clock(a);
	SolverCube.rotate_clock(a); SolverCube.rotate_clock(a); white_bottom(c);
}

void Solver::white_bottom_inverted(char q)
{
	if (SolverCube.blue[3] == 'w' || SolverCube.red[3] == 'w' || SolverCube.green[3] == 'w' || SolverCube.orange[3] == 'w')
	{
		if (SolverCube.blue[3] == 'w' && SolverCube.yellow[0] == q)
		{
			inv_alg('b', 'r', q);
		}
		if (SolverCube.red[3] == 'w' && SolverCube.yellow[2] == q)
		{
			inv_alg('r', 'g', q);
		}
		if (SolverCube.green[3] == 'w' && SolverCube.yellow[4] == q)
		{
			inv_alg('g', 'o', q);
		}
		if (SolverCube.orange[3] == 'w' && SolverCube.yellow[6] == q)
		{
			inv_alg('o', 'b', q);
		}
	}
}

void Solver::solve_white_cross()
{
	if (is_it_full()) {
		return;
	}
	char prefer[4] = { 'b','r','g','o' };
	for (int i = 0; i < 4; i++)
	{
		if (SolverCube.white[0] == 'w' && SolverCube.blue[7] == prefer[i]) { SolverCube.rotate_clock('b'); }
		if (SolverCube.white[2] == 'w' && SolverCube.red[7] == prefer[i]) { SolverCube.rotate_clock('r'); }
		if (SolverCube.white[4] == 'w' && SolverCube.green[7] == prefer[i]) { SolverCube.rotate_clock('g'); }
		if (SolverCube.white[6] == 'w' && SolverCube.orange[7] == prefer[i]) { SolverCube.rotate_clock('o'); }
		white_bottom(prefer[i]); white_bottom_inverted(prefer[i]); white_left(prefer[i]); white_right(prefer[i]); white_top(prefer[i]);
		if (i != 0)
		{
			while (SolverCube.blue[7] != 'b') { SolverCube.rotate_clock('w'); }
		}
		if (SolverCube.white[0] == 'w' && SolverCube.white[2] == 'w' && SolverCube.white[4] == 'w' && SolverCube.white[6] == 'w' && SolverCube.blue[7] == 'b' && SolverCube.red[7] == 'r' && SolverCube.green[7] == 'g' && SolverCube.orange[7] == 'o')
		{
			break;
		}
	}
}

void Solver::white_corners_alg_left()
{
	SolverCube.rotate_clock('b'); SolverCube.rotate_clock('b'); SolverCube.rotate_clock('b');
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('b');
}

void Solver::white_corners_alg_right()
{
	SolverCube.rotate_clock('r');
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r');
}

void Solver::solve_white_corners()
{
	if (is_it_full()) {
		return;
	}
	while (SolverCube.red[0] != 'r' || SolverCube.red[6] != 'r' || SolverCube.blue[0] != 'b' || SolverCube.blue[6] != 'b' || SolverCube.orange[0] != 'o' || SolverCube.orange[6] != 'o' || SolverCube.green[0] != 'g' || SolverCube.green[6] != 'g')
	{
		while (SolverCube.red[7] != 'r')
		{
			SolverCube.rotate_clock('w');
		}
		if (SolverCube.blue[4] == 'w' || SolverCube.red[4] == 'w' || SolverCube.green[4] == 'w' || SolverCube.orange[4] == 'w')
		{
			while (SolverCube.blue[4] != 'w')
			{
				SolverCube.rotate_clock('y');
			}
			while (SolverCube.red[2] != SolverCube.red[7])
			{
				SolverCube.rotate_clock('w');
			}
			white_corners_alg_left();
			while (SolverCube.red[7] != 'r')
			{
				SolverCube.rotate_clock('w');
			}
		}
		else if (SolverCube.blue[2] == 'w' || SolverCube.red[2] == 'w' || SolverCube.green[2] == 'w' || SolverCube.orange[2] == 'w')
		{
			while (SolverCube.red[2] != 'w')
			{
				SolverCube.rotate_clock('y');
			}
			while (SolverCube.red[7] != SolverCube.yellow[1])
			{
				SolverCube.rotate_clock('w');
			}
			white_corners_alg_right();
			while (SolverCube.red[7] != 'r')
			{
				SolverCube.rotate_clock('w');
			}
		}
		else if (SolverCube.yellow[1] == 'w' || SolverCube.yellow[3] == 'w' || SolverCube.yellow[5] == 'w' || SolverCube.yellow[7] == 'w')
		{
			while (SolverCube.yellow[1] != 'w')
			{
				SolverCube.rotate_clock('y');
			}
			while (SolverCube.red[2] != SolverCube.blue[7])
			{
				SolverCube.rotate_clock('w');
			}
			SolverCube.rotate_clock('b'); SolverCube.rotate_clock('b'); SolverCube.rotate_clock('b');
			SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
			SolverCube.rotate_clock('b');
			while (SolverCube.blue[4] != 'w')
			{
				SolverCube.rotate_clock('y');
			}
			while (SolverCube.red[2] != SolverCube.red[7])
			{
				SolverCube.rotate_clock('w');
			}
			white_corners_alg_left();
			while (SolverCube.red[7] != 'r')
			{
				SolverCube.rotate_clock('w');
			}
		}
		else
		{
			while (SolverCube.red[7] == SolverCube.red[0])
			{
				SolverCube.rotate_clock('w');
			}
			white_corners_alg_left();
			while (SolverCube.red[7] != 'r')
			{
				SolverCube.rotate_clock('w');
			}
		}
	}
}

void Solver::middle_place_left_alg(char left, char center)
{
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock(left); SolverCube.rotate_clock(left); SolverCube.rotate_clock(left);
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock(left);
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock(center);
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock(center); SolverCube.rotate_clock(center); SolverCube.rotate_clock(center);
}

void Solver::middle_place_right_alg(char center, char right)
{
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock(right);
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock(right); SolverCube.rotate_clock(right); SolverCube.rotate_clock(right);
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock(center); SolverCube.rotate_clock(center); SolverCube.rotate_clock(center);
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock(center);
}

void Solver::solve_middle_layer()
{
	if (is_it_full()) {
		return;
	}
	while (SolverCube.red[5] != 'r' || SolverCube.red[1] != 'r' || SolverCube.blue[1] != 'b' || SolverCube.blue[5] != 'b' || SolverCube.orange[1] != 'o' || SolverCube.orange[5] != 'o' || SolverCube.green[1] != 'g' || SolverCube.green[5] != 'g')
	{

		if ((SolverCube.orange[1] != 'o' && SolverCube.green[5] != 'g') && (SolverCube.orange[1] != 'y' || SolverCube.green[5] != 'y'))
		{
			while (SolverCube.green[3] != 'y' && SolverCube.yellow[4] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			middle_place_right_alg('g', 'o');
		}

		else if ((SolverCube.orange[5] != 'o' && SolverCube.blue[1] != 'b') && (SolverCube.orange[5] != 'y' || SolverCube.blue[1] != 'y'))
		{
			while (SolverCube.orange[3] != 'y' && SolverCube.yellow[6] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			middle_place_right_alg('o', 'b');
		}

		else if ((SolverCube.blue[5] != 'b' && SolverCube.red[1] != 'r') && (SolverCube.blue[5] != 'y' || SolverCube.red[1] != 'y'))
		{
			while (SolverCube.blue[3] != 'y' && SolverCube.yellow[0] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			middle_place_right_alg('b', 'r');
		}

		else if ((SolverCube.red[5] != 'r' && SolverCube.green[1] != 'g') && (SolverCube.red[5] != 'y' || SolverCube.green[1] != 'y'))
		{
			while (SolverCube.red[3] != 'y' && SolverCube.yellow[2] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			middle_place_right_alg('r', 'g');
		}

		while (SolverCube.red[3] == 'y' || SolverCube.yellow[2] == 'y')
		{
			SolverCube.rotate_clock('y');
		}

		if (SolverCube.red[3] == 'r' && SolverCube.yellow[2] != 'y')
		{
			if (SolverCube.yellow[2] == 'g')
			{
				middle_place_right_alg('r', 'g');
			}
			else if (SolverCube.yellow[2] = 'b')
			{
				middle_place_left_alg('b', 'r');
			}
		}
		else if (SolverCube.red[3] == 'b' && SolverCube.yellow[2] != 'y')
		{
			SolverCube.rotate_clock('y');
			if (SolverCube.yellow[0] == 'r')
			{
				middle_place_right_alg('b', 'r');
			}
			else if (SolverCube.yellow[0] = 'o')
			{
				middle_place_left_alg('o', 'b');
			}
		}
		else if (SolverCube.red[3] == 'o' && SolverCube.yellow[2] != 'y')
		{
			SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
			if (SolverCube.yellow[6] == 'b')
			{
				middle_place_right_alg('o', 'b');
			}
			else if (SolverCube.yellow[6] = 'g')
			{
				middle_place_left_alg('g', 'o');
			}
		}
		else if (SolverCube.red[3] == 'g' && SolverCube.yellow[2] != 'y')
		{
			SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
			if (SolverCube.yellow[4] == 'o')
			{
				middle_place_right_alg('g', 'o');
			}
			else if (SolverCube.yellow[4] = 'r')
			{
				middle_place_left_alg('r', 'g');
			}
		}
	}
}

void Solver::yellow_cross_algorithm()
{
	SolverCube.rotate_clock('r');
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r');
}

void Solver::solve_yellow_cross()
{
	if (is_it_full()) {
		return;
	}
	while (SolverCube.yellow[0] != 'y' || SolverCube.yellow[2] != 'y' || SolverCube.yellow[4] != 'y' || SolverCube.yellow[6] != 'y')
	{
		if ((SolverCube.yellow[0] == 'y' && SolverCube.yellow[6] == 'y') || (SolverCube.yellow[4] == 'y' && SolverCube.yellow[6] == 'y')
			|| (SolverCube.yellow[2] == 'y' && SolverCube.yellow[4] == 'y') || (SolverCube.yellow[0] == 'y' && SolverCube.yellow[2] == 'y'))
		{
			while (SolverCube.yellow[0] != 'y' && SolverCube.yellow[6] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			yellow_cross_algorithm();
		}
		if ((SolverCube.yellow[2] == 'y' && SolverCube.yellow[6] == 'y') || (SolverCube.yellow[0] == 'y' && SolverCube.yellow[4] == 'y'))
		{
			while (SolverCube.yellow[0] != 'y' && SolverCube.yellow[4] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			yellow_cross_algorithm();
			yellow_cross_algorithm();
		}
		else if (SolverCube.yellow[8] == 'y')
		{
			yellow_cross_algorithm();
			SolverCube.rotate_clock('y');
			yellow_cross_algorithm();
			yellow_cross_algorithm();
		}
	}
}

void Solver::yellow_corners_algorithm()
{
	SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g');
}

void Solver::solve_yellow_corners()
{
	if (is_it_full()) {
		return;
	}
	while (SolverCube.yellow[1] != 'y' || SolverCube.yellow[3] != 'y' || SolverCube.yellow[5] != 'y' || SolverCube.yellow[7] != 'y')
	{
		if ((SolverCube.yellow[1] == 'y' && SolverCube.yellow[3] != 'y' && SolverCube.yellow[5] != 'y' && SolverCube.yellow[7] != 'y')
			|| (SolverCube.yellow[3] == 'y' && SolverCube.yellow[1] != 'y' && SolverCube.yellow[5] != 'y' && SolverCube.yellow[7] != 'y')
			|| (SolverCube.yellow[5] == 'y' && SolverCube.yellow[1] != 'y' && SolverCube.yellow[3] != 'y' && SolverCube.yellow[7] != 'y')
			|| (SolverCube.yellow[7] == 'y' && SolverCube.yellow[1] != 'y' && SolverCube.yellow[3] != 'y' && SolverCube.yellow[5] != 'y'))
		{
			while (SolverCube.yellow[1] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((SolverCube.green[2] == 'y' && SolverCube.green[4] == 'y' && SolverCube.yellow[1] == 'y' && SolverCube.yellow[7] == 'y')
			|| (SolverCube.orange[2] == 'y' && SolverCube.orange[4] == 'y' && SolverCube.yellow[1] == 'y' && SolverCube.yellow[3] == 'y')
			|| (SolverCube.blue[2] == 'y' && SolverCube.blue[4] == 'y' && SolverCube.yellow[3] == 'y' && SolverCube.yellow[5] == 'y')
			|| (SolverCube.red[2] == 'y' && SolverCube.red[4] == 'y' && SolverCube.yellow[5] == 'y' && SolverCube.yellow[7] == 'y'))
		{
			while (SolverCube.red[2] != 'y' && SolverCube.red[4] != 'y' && SolverCube.yellow[5] != 'y' && SolverCube.yellow[7] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((SolverCube.red[4] == 'y' && SolverCube.orange[2] == 'y' && SolverCube.yellow[1] == 'y' && SolverCube.yellow[7] == 'y')
			|| (SolverCube.blue[2] == 'y' && SolverCube.green[4] == 'y' && SolverCube.yellow[1] == 'y' && SolverCube.yellow[3] == 'y')
			|| (SolverCube.red[2] == 'y' && SolverCube.orange[4] == 'y' && SolverCube.yellow[3] == 'y' && SolverCube.yellow[5] == 'y')
			|| (SolverCube.blue[4] == 'y' && SolverCube.green[2] == 'y' && SolverCube.yellow[5] == 'y' && SolverCube.yellow[7] == 'y'))
		{
			while (SolverCube.red[2] != 'y' && SolverCube.orange[4] != 'y' && SolverCube.yellow[3] != 'y' && SolverCube.yellow[5] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((SolverCube.green[2] == 'y' && SolverCube.green[4] == 'y' && SolverCube.blue[2] == 'y' && SolverCube.blue[4] == 'y')
			|| (SolverCube.red[2] == 'y' && SolverCube.red[4] == 'y' && SolverCube.orange[2] == 'y' && SolverCube.orange[4] == 'y'))
		{
			while (SolverCube.green[2] != 'y' && SolverCube.green[4] != 'y' && SolverCube.blue[2] != 'y' && SolverCube.blue[4] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((SolverCube.green[2] == 'y' && SolverCube.orange[2] == 'y' && SolverCube.orange[4] == 'y' && SolverCube.blue[4] == 'y')
			|| (SolverCube.red[4] == 'y' && SolverCube.orange[2] == 'y' && SolverCube.blue[2] == 'y' && SolverCube.blue[4] == 'y')
			|| (SolverCube.red[2] == 'y' && SolverCube.red[4] == 'y' && SolverCube.green[4] == 'y' && SolverCube.blue[2] == 'y')
			|| (SolverCube.green[2] == 'y' && SolverCube.green[4] == 'y' && SolverCube.orange[4] == 'y' && SolverCube.red[2] == 'y'))
		{
			while (SolverCube.green[2] != 'y' && SolverCube.orange[2] != 'y' && SolverCube.orange[4] != 'y' && SolverCube.blue[4] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
		else if ((SolverCube.yellow[1] == 'y' && SolverCube.yellow[5] == 'y' && SolverCube.yellow[3] != 'y' && SolverCube.yellow[7] != 'y')
			|| (SolverCube.yellow[3] == 'y' && SolverCube.yellow[7] == 'y' && SolverCube.yellow[1] != 'y' && SolverCube.yellow[5] != 'y'))
		{
			while (SolverCube.red[2] != 'y' && SolverCube.green[4] != 'y')
			{
				SolverCube.rotate_clock('y');
			}
			yellow_corners_algorithm();
		}
	}
}

void Solver::yellow_corner_orientation_algorithm()
{
	SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('r');
	SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('o'); SolverCube.rotate_clock('o');
	SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r');
	SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('o'); SolverCube.rotate_clock('o');
	SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
}

void Solver::yellow_corner_orientation()
{
	if (is_it_full()) {
		return;
	}
	while (SolverCube.red[2] != 'r' || SolverCube.red[4] != 'r' || SolverCube.green[2] != 'g' || SolverCube.green[4] != 'g'
		|| SolverCube.orange[2] != 'o' || SolverCube.orange[4] != 'o' || SolverCube.blue[2] != 'b' || SolverCube.blue[4] != 'b')
	{
		if ((SolverCube.red[2] == SolverCube.red[4]) || (SolverCube.green[2] == SolverCube.green[4]) || (SolverCube.orange[2] == SolverCube.orange[4]) || (SolverCube.blue[2] == SolverCube.blue[4]))
		{
			while (SolverCube.orange[2] != SolverCube.orange[4])
			{
				SolverCube.rotate_clock('y');
			}
			yellow_corner_orientation_algorithm();
			while (SolverCube.blue[2] != 'b')
			{
				SolverCube.rotate_clock('y');
			}
		}
		else
		{
			while (SolverCube.orange[4] != 'o' && SolverCube.red[4] != 'r')
			{
				SolverCube.rotate_clock('y');
			}
			yellow_corner_orientation_algorithm();
			while (SolverCube.orange[2] != SolverCube.orange[4])
			{
				SolverCube.rotate_clock('y');
			}
			yellow_corner_orientation_algorithm();
			while (SolverCube.blue[2] != 'b')
			{
				SolverCube.rotate_clock('y');
			}
		}
	}
}

void Solver::yellow_edges_colour_arrangement_right()
{
	SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r');
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('b');
	SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r');
	SolverCube.rotate_clock('b'); SolverCube.rotate_clock('b'); SolverCube.rotate_clock('b');
	SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y'); SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r');
}

void Solver::yellow_edges_colour_arrangement_left()
{
	SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r');
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('b');
	SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g'); SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r');
	SolverCube.rotate_clock('b'); SolverCube.rotate_clock('b'); SolverCube.rotate_clock('b');
	SolverCube.rotate_clock('g');
	SolverCube.rotate_clock('y');
	SolverCube.rotate_clock('r'); SolverCube.rotate_clock('r');
}

void Solver::yellow_edges_colour_arrangement()
{
	if (is_it_full()) {
		return;
	}
	while (SolverCube.red[2] != 'r')
	{
		SolverCube.rotate_clock('r');
	}
	if (SolverCube.red[3] == 'o' && SolverCube.orange[3] == 'r' && SolverCube.blue[3] == 'g' && SolverCube.green[3] == 'b')
	{
		yellow_edges_colour_arrangement_left();
	}
	else if (SolverCube.red[3] == 'b' && SolverCube.blue[3] == 'r')
	{
		yellow_edges_colour_arrangement_left();
	}
	else if (SolverCube.red[3] == 'g' && SolverCube.green[3] == 'r')
	{
		yellow_edges_colour_arrangement_left();
	}
	while (SolverCube.orange[2] != SolverCube.orange[3])
	{
		SolverCube.rotate_clock('y');
	}
	if (SolverCube.red[3] == SolverCube.green[2])
	{
		yellow_edges_colour_arrangement_right();
	}
	else if (SolverCube.red[3] == SolverCube.blue[2])
	{
		yellow_edges_colour_arrangement_left();
	}
	while (SolverCube.red[3] != 'r')
	{
		SolverCube.rotate_clock('y');
	}
}

bool Solver::is_it_full() {
	bool result = false;
	for (int i = 0; i < 9; ++i) {
		if (SolverCube.white[i] == 'w' && SolverCube.red[i] == 'r' && SolverCube.orange[i] == 'o' && SolverCube.blue[i] == 'b' && SolverCube.green[i] == 'g' && SolverCube.yellow[i] == 'y') {
			result = true;
		}
		else return false;
	}
	return result;
}

void Solver::solve() {
	std::cout << "\n-------------------------------------------------\n" << std::endl;
	std::cout << "Turn these sides of the Cube in Clockwise Direction by 90 degrees in this exact order..." << std::endl << std::endl;
	solve_white_cross();
	std::cout << "After assembling the white cross:\n";
	SolverCube.display_all_cube();
	solve_white_corners();
	std::cout << "\n-------------------------------------------------\n" << std::endl;
	std::cout << "After assembling the white corners:\n";
	SolverCube.display_all_cube();
	solve_middle_layer();
	std::cout << "\n-------------------------------------------------\n" << std::endl;
	std::cout << "After assembling the middle layer:\n";
	SolverCube.display_all_cube();
	solve_yellow_cross();
	std::cout << "\n-------------------------------------------------\n" << std::endl;
	std::cout << "After assembling the yellow cross:\n";
	SolverCube.display_all_cube();
	solve_yellow_corners();
	std::cout << "\n-------------------------------------------------\n" << std::endl;
	std::cout << "After assembling yellow corners:\n";
	SolverCube.display_all_cube();
	yellow_corner_orientation();
	std::cout << "\n-------------------------------------------------\n" << std::endl;
	std::cout << "After assembling the corner orientation:\n";
	SolverCube.display_all_cube();
	yellow_edges_colour_arrangement();
	std::cout << "\n-------------------------------------------------\n" << std::endl;
	std::cout << "After assembling the colour arrangement:\n";
	SolverCube.display_all_cube();
	std::cout << "\n-------------------------------------------------" << std::endl << std::endl;
	std::cout << "Your Rubik's Cube is now SOLVED!\n\nOutput : " << std::endl;
	SolverCube.display_all_cube();
}

void CubicRubica::clockwise_rotate(char choice)
{
	if (choice == 'w')
	{
		swap(white[7], white[3]);
		swap(white[6], white[4]);
		swap(white[0], white[2]);
		swap(white[7], white[5]);
		swap(white[0], white[4]);
		swap(white[1], white[3]);
		//-------------------------
		swap(blue[0], orange[0]);
		swap(blue[7], orange[7]);
		swap(blue[6], orange[6]);
		swap(orange[6], green[6]);
		swap(orange[7], green[7]);
		swap(orange[0], green[0]);
		swap(green[6], red[6]);
		swap(green[7], red[7]);
		swap(green[0], red[0]);
	}
	//-------------------------
	else if (choice == 'r')
	{
		swap(red[0], red[4]);
		swap(red[7], red[5]);
		swap(red[1], red[3]);
		swap(red[0], red[6]);
		swap(red[1], red[5]);
		swap(red[2], red[4]);
		//-------------------------
		swap(blue[6], white[3]);
		swap(blue[5], white[2]);
		swap(blue[4], white[1]);
		swap(white[1], green[0]);
		swap(white[2], green[1]);
		swap(white[3], green[2]);
		swap(green[0], yellow[3]);
		swap(green[1], yellow[2]);
		swap(green[2], yellow[1]);
		//--------------------------
	}
	//-----------------------------------
	else if (choice == 'y')
	{
		swap(yellow[1], yellow[5]);
		swap(yellow[2], yellow[4]);
		swap(yellow[0], yellow[6]);
		swap(yellow[1], yellow[3]);
		swap(yellow[0], yellow[4]);
		swap(yellow[7], yellow[5]);
		//--------------------------
		swap(blue[4], red[4]);
		swap(blue[3], red[3]);
		swap(blue[2], red[2]);
		swap(red[2], green[2]);
		swap(red[3], green[3]);
		swap(red[4], green[4]);
		swap(green[4], orange[4]);
		swap(green[3], orange[3]);
		swap(green[2], orange[2]);
		//--------------------------
	}
	//-------------------------------------
	else if (choice == 'o')
	{
		swap(orange[4], orange[0]);
		swap(orange[3], orange[1]);
		swap(orange[5], orange[7]);
		swap(orange[4], orange[2]);
		swap(orange[5], orange[1]);
		swap(orange[6], orange[0]);
		//--------------------------
		swap(blue[2], yellow[5]);
		swap(blue[1], yellow[6]);
		swap(blue[0], yellow[7]);
		swap(yellow[5], green[6]);
		swap(yellow[6], green[5]);
		swap(yellow[7], green[4]);
		swap(green[6], white[7]);
		swap(green[5], white[6]);
		swap(green[4], white[5]);
		//--------------------------
	}
	//-------------------------------------
	else if (choice == 'g')
	{
		swap(green[6], green[2]);
		swap(green[5], green[3]);
		swap(green[7], green[1]);
		swap(green[4], green[6]);
		swap(green[7], green[3]);
		swap(green[0], green[2]);
		//--------------------------
		swap(white[5], orange[2]);
		swap(white[4], orange[1]);
		swap(white[3], orange[0]);
		swap(yellow[3], orange[2]);
		swap(yellow[4], orange[1]);
		swap(yellow[5], orange[0]);
		swap(yellow[3], red[6]);
		swap(yellow[4], red[5]);
		swap(yellow[5], red[4]);
		//--------------------------
	}
	//-------------------------------------------
	else if (choice == 'b')
	{
		swap(blue[1], blue[7]);
		swap(blue[2], blue[6]);
		swap(blue[5], blue[3]);
		swap(blue[2], blue[0]);
		swap(blue[7], blue[3]);
		swap(blue[6], blue[4]);
		//--------------------------
		swap(yellow[1], orange[4]);
		swap(yellow[0], orange[5]);
		swap(yellow[7], orange[6]);
		swap(white[7], orange[4]);
		swap(white[0], orange[5]);
		swap(white[1], orange[6]);
		swap(white[7], red[0]);
		swap(white[0], red[1]);
		swap(white[1], red[2]);
		//--------------------------
	}
}

void CubicRubica::random() {
	for (int i = 0; i < 9; i++) {
		white[i] = 'w';
		red[i] = 'r';
		orange[i] = 'o';
		blue[i] = 'b';
		green[i] = 'g';
		yellow[i] = 'y';
	};

	std::srand(time(nullptr));
	char command[9] = { 'w', 'r', 'o', 'b', 'g', 'y' };

	int random_variable = std::rand();
	for (int n = 0; n < 100; n++)
	{
		int i = 0;
		while (i < 9)
		{
			i = std::rand() / ((RAND_MAX + 1u) / 9);
			clockwise_rotate(command[i]);
		}
	}
}

void CubicRubica::base()
{
	for (int i = 0; i < 9; i++) {
		white[i] = 'w';
		red[i] = 'r';
		orange[i] = 'o';
		blue[i] = 'b';
		green[i] = 'g';
		yellow[i] = 'y';
	};
}

bool CubicRubica::is_assembled()
{
	bool result = false;
	for (int i = 0; i < 9; ++i) {
		if (white[i] == 'w' && red[i] == 'r' && orange[i] == 'o' && blue[i] == 'b' && green[i] == 'g' && yellow[i] == 'y') {
			result = true;
		}
		else return false;
	}
	return result;
}