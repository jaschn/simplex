// simplex_console.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "../simplex/simplex.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
		return -1;
	simplex a;
	if (a.parse_file(argv[1]))
	{
		a.solve();
		auto results = a.get_result_values();
		double res = a.get_result();
		std::cout << "result:" << std::endl;	
		for (int i = 0; i < results.size(); i++)
		{
			std::cout << "x_" << i << ": " << results.at(i) << std::endl;
		}
		std::cout << "result value: " << res << std::endl;
	}
	int tmp;
	std::cin >> tmp;
}
