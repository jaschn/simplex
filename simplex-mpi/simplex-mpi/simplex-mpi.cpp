// simplex-mpi.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

//max: 6*x1 + 5*x2
//x1 + x2 <= 5
//3*x1 + 2*x2 <= 12
//x1,x2 >= 0

#include "pch.h"
#include <iostream>
#include "simplex.h"

int main()
{    
	simplex a;
	a.parse_file("../../example.txt");
	a.solve();
}
