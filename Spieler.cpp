#include <iostream>
#include "Spieler.h"
#include <string>
#include "Mensch.h"
#include "SpielfeldT.h"
using namespace std;

Spieler::Spieler(Chip pFarbe, string pName, SpielfeldT* pS) {
	s = pS;
	name = pName;
	farbe = pFarbe;
}

Spieler::Spieler() {
	farbe = gelb;
	name = "";
	s; 
}

string Spieler::getName() {

	return name;
}
Chip Spieler::getFarbe() {

	return farbe;
}