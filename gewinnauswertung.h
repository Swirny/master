#pragma once

// AT: Includes hinzugef�gt
#include "SpielfeldT.h"
#include "Spieler.h"

// AT: Spielfeld in SpielfeldT ge�ndert
bool ueberpruefeGewinner (const SpielfeldT& pSpielfeld, const Punkt& pLetzterPunkt);
bool istUnentschieden (const SpielfeldT& pSpielfeld);
