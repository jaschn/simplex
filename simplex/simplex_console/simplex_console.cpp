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
	a.parse_file(argv[1]);
	a.solve();
	double a_res = a.get_results();
}
