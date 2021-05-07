// Checkers_bot.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <array>
#include <vector>
#include <chrono>
#include "Turn.h"
#include "Graph_of_the_game.h"
#include "Best_turn.h"
#include "Checkers_bot.h"

int main()
{
	std::array<std::array<gotg::VALUES_FOR_FIELD, turn::width_of_field>, turn::heigh_of_field> my_field;
	for (int i = 0; i < 8; i++)
	{
		my_field[3][i] = gotg::VALUES_FOR_FIELD::FREE_CAGES;
		my_field[4][i] = gotg::VALUES_FOR_FIELD::FREE_CAGES;
		if (i % 2 == 0)
		{
			my_field[0][i] = gotg::VALUES_FOR_FIELD::FREE_CAGES;
			my_field[1][i] = gotg::VALUES_FOR_FIELD::MY_CHECKERS;
			my_field[2][i] = gotg::VALUES_FOR_FIELD::FREE_CAGES;
			my_field[5][i] = gotg::VALUES_FOR_FIELD::ENEMY_CHECKERS;
			my_field[6][i] = gotg::VALUES_FOR_FIELD::FREE_CAGES;
			my_field[7][i] = gotg::VALUES_FOR_FIELD::ENEMY_CHECKERS;
		}
		else
		{
			my_field[0][i] = gotg::VALUES_FOR_FIELD::MY_CHECKERS;
			my_field[1][i] = gotg::VALUES_FOR_FIELD::FREE_CAGES;
			my_field[2][i] = gotg::VALUES_FOR_FIELD::MY_CHECKERS;
			my_field[5][i] = gotg::VALUES_FOR_FIELD::FREE_CAGES;
			my_field[6][i] = gotg::VALUES_FOR_FIELD::ENEMY_CHECKERS;
			my_field[7][i] = gotg::VALUES_FOR_FIELD::FREE_CAGES;
		}
	}

	my_field[3][2] = gotg::VALUES_FOR_FIELD::ENEMY_CHECKERS;
	my_field[6][3] = gotg::VALUES_FOR_FIELD::FREE_CAGES;

	my_field[4][5] = gotg::VALUES_FOR_FIELD::MY_CHECKERS;
	my_field[2][5] = gotg::VALUES_FOR_FIELD::FREE_CAGES;

	auto value_turn_finder = [](bt::Eaten_checkers e_checkers) -> double
	{
		return static_cast<double>(e_checkers.count_of_enemy_cheakers) - static_cast<double>(e_checkers.count_of_my_cheakers);
	};

	std::cout << "Best turn is: " << std::endl << ch_bot::get_the_best_turn(my_field, gotg::VALUES_FOR_FIELD::MY_CHECKERS, 3, value_turn_finder) << std::endl;;
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
