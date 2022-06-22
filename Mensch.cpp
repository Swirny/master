#include <iostream>
#include "Spieler.h"
#include <string>
#include "Mensch.h"
#include "SpielfeldT.h"
using namespace std;

Mensch::Mensch(Chip pFarbe, SpielfeldT* pS){
    //AT: Zeile s = pS nach oben geschoben
    s = pS;
    s->drawInfo("Wie lautet der Name? \n", 1);
	name = s->getStringInput();
	farbe = pFarbe;
}

Punkt Mensch::naechsterZug() {
	bool spalteVoll = true;
	int reihe = 0;
	int spalte = 0;
	while (spalteVoll) {
		//eingabe
		bool richtigeEingabe = false;
		while (richtigeEingabe == false) {
			s->drawInfo("In welche Spalte möchtest du deinen Chip werfen?\n", 1);
			spalte = s->getIntInput();
			if (spalte > 1 && spalte < 7) {
				richtigeEingabe = true;
			}
			else {
				s->drawInfo("Deine Eingabe ist ungueltig.\n",1); 
			}
		}
		spalteVoll = false;
		//ermittlung Position
		int counter = 1;
		
		while (s->getPunkt(spalte, counter) != leer && counter <= 6) {
			counter++;
		}
		if (counter == 7) {
			spalteVoll = true;
			s->drawInfo("Die Spalte ist berits voll.\n", 1);
		}
		else {
			reihe = counter;
		}
	}
	//Setzen des Punktes
	s->setPunkt(farbe,spalte,reihe);
	//Rückgabe des Punktes
	Punkt p = { reihe,spalte};
	return p;
}
