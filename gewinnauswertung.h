#pragma once

// AT: Includes hinzugefügt
#include "SpielfeldT.h"
#include "Spieler.h"

// AT: Spielfeld in SpielfeldT geändert
bool ueberpruefeGewinner (const SpielfeldT& pSpielfeld, const Punkt& pLetzterPunkt);
bool istUnentschieden (const SpielfeldT& pSpielfeld);
