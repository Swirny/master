#pragma once
using namespace std;
#include <windows.h>
#include <iostream>
#include "SpielfeldT.h"

//Modulname:
//
//Modulbeschreibung:
//
//
//importe:
//zero vom other modules
//
//
//exporte:
//
//getSpielfeld
//getChip
//getZeile
//getSpalte
//
//setChip

enum Chip {
	gelb, rot, leer
};


class SpielfeldT {
private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Chip feld[7][6];
	//spielfeld ausgeben
	void drawClearSpielfeld();
	//chip ausgeben
	void drawPunkt(Chip chip, int spalte, int zeile);

public:
	////gibt ein Array [0] bis [5] von Chip enums der übergebenen Spalte x(1-7) aus
	//Chip getSpalte(int spalte);

	////gibt ein Array [0] bis [6] von Chip enums der übergebenen Zeile x(1-6) aus
	//Chip getZeile(int zeile);

	//gibt den Chip enum des übergebenen Punktes aus (Spalte 1-7, Zeile 1-6)
	// (1,1) ist unten links, (7,6) ist oben rechts
	Chip getPunkt(int spalte, int zeile) const;

	//setzt und zeichnet den übergebenen Chip (enum) an den übergebenen Punkt (Spalte 1-7, Zeile 1-6)
	// (1,1) ist unten links, (7,6) ist oben rechts
	void setPunkt(Chip chip, int spalte, int zeile);

	//erstellt das (leere) Spielfeld
	SpielfeldT();

	//leert das Spielfeld (und gibt es aus)
	void clearSpielfeld();

	//löscht das Spielfeld
	~SpielfeldT();

	//Text unterhalb des Spielfeldes anzeigen: maxmimal 5 Zeilen getrennt mit \n
	void drawInfo(string text, int startlinie = 1);

	//nur nach drawInfo nutzen! returned eingegeben Wert.
	//Bsp.: drawInfo("bitte Zeile eingeben: "); getÍntInput();
	string getStringInput();
	int getIntInput();
	//void getStringInput(string& var);
	//void getIntInput(int& var);
};
