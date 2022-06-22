#pragma once

#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include <random>
#include <string>

#include "SpielfeldT.h"
#include "Spieler.h"

class Computer : public Spieler
{
public:
	Computer(Chip chip, std::string name, SpielfeldT* spielfeld);

	// Gibt die Position des nächsten Zuges zurück
	virtual Punkt naechsterZug() override;

private:
	std::mt19937 randomEngine;

	static constexpr int reihen = 6;
	static constexpr int spalten = 7;
};

#endif // !_COMPUTER_H_
