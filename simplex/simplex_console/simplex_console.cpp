// simplex_console.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "../simplex/simplex.h"

int main()
{
	simplex a;
	a.parse_file("../../KI_15.txt");
	a.solve();
	double a_res = a.get_results();

	int x = 0;
	//simplex b;
	//b.parse_file("../../KI_8.txt");
	//b.solve();
	//double b_res = b.get_results();

	//simplex c;
	//c.parse_file("../../KI_9.txt");
	//c.solve();
	//double c_res = c.get_results();

	//simplex d;
	//d.parse_file("../../KI_10.txt");
	//d.solve();
	//double d_res = d.get_results();

	//simplex e;
	//e.parse_file("../../KI_15.txt");
	//e.solve();
	//double e_res = e.get_results();

	//simplex f;
	//f.parse_file("../../KI_20.txt");
	//f.solve();
	//double f_res = f.get_results();

	//simplex g;
	//g.parse_file("../../KI_20.txt");
	//g.solve();
	//double g_res = g.get_results();
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
