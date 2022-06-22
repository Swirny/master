#pragma once
#include <iostream>
#include <string>
#include "SpielfeldT.h"
using namespace std;

struct Punkt {
	int zeile;
	int spalte;
};

class Spieler {
protected:
string name; 
Chip farbe;
SpielfeldT* s;
public:
	Spieler();
	Spieler(Chip pFarbe,string pName, SpielfeldT* pS);
	/*Position ermittelt und Chip wird gesetzt durch setPunkt im Spielfeld;
	eingesetzter Punkt wird zurückgegeben */
		virtual Punkt naechsterZug() = 0;
		string getName();
		Chip getFarbe();
};



