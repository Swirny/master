#pragma once
#include <iostream>
#include "Spieler.h"
#include <string>
#include "SpielfeldT.h"
using namespace std;
class Mensch : public Spieler{
public:
	Mensch(Chip pFarbe, SpielfeldT* pS);
	Punkt naechsterZug();
};


