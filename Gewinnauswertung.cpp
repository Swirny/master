#include "gewinnauswertung.h"

// AT: Funktionsdeklarationen hinzugefügt
int pruefeLinks(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip);
int pruefeRechts(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip);
int pruefeUnten(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip);
int pruefeObenLinks(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip);
int pruefeUntenRechts(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip);
int pruefeObenRechts(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip);
int pruefeUntenLinks(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip);

bool ueberpruefeGewinner(const SpielfeldT& spielfeld, const Punkt& letzterPunkt)
{
	//Welche Farbe hat der neu eingeworfener Chip?
	Chip chip = spielfeld.getPunkt(letzterPunkt.zeile, letzterPunkt.spalte);
	
	

	
	int summeHorizontal = 1;
	summeHorizontal += pruefeLinks(spielfeld, letzterPunkt, chip);
	summeHorizontal += pruefeRechts(spielfeld, letzterPunkt, chip);

	


	//Überprüfung der Diagonalen
	int summeDiagonaleLR = 1;
	summeDiagonaleLR += pruefeObenLinks(spielfeld, letzterPunkt, chip);
	summeDiagonaleLR += pruefeObenLinks(spielfeld, letzterPunkt, chip);
	

	int summeDiagonaleRL = 1;
	summeDiagonaleRL = pruefeObenRechts(spielfeld, letzterPunkt, chip);
	summeDiagonaleRL = pruefeUntenLinks(spielfeld, letzterPunkt, chip);
	

	if (summeHorizontal >= 4 || pruefeUnten(spielfeld, letzterPunkt, chip) >= 3 || summeDiagonaleLR >= 4 || summeDiagonaleRL >= 4)
		return true;
	else
		return false;
}

int pruefeLinks(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip)
{
	int counter = 0;
	for (int i = 1; i < 4; i++)
	{
		if (letzterPunkt.spalte - i >= 1)
		{
			if (chip == spielfeld.getPunkt(letzterPunkt.zeile, letzterPunkt.spalte - i))
			{
				counter++;
				continue;
			}
			else
				return counter;
		}
		else
			break;
	}
	
    // AT: hinzugefügt
    return counter;
}

int pruefeRechts(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip)
{
	int counter = 0;
	
	for (int i = 1; i < 4; i++)
	{
		if (letzterPunkt.spalte + i <= 7)
		{
			if (chip == spielfeld.getPunkt(letzterPunkt.zeile, letzterPunkt.spalte + i))
			{
				counter++;
				continue;
			}
			else
				return counter;
		}
		
	}

    // AT: hinzugefügt
    return counter;
}

int pruefeUnten(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip) 
{
	int counter = 0;

	for (int i = 1; i < 4; i++)
	{
		if (letzterPunkt.zeile + i >= 1)
		{
			if (chip == spielfeld.getPunkt(letzterPunkt.zeile, letzterPunkt.zeile - i))
			{
				counter++;
				continue;
			}
			else
				return counter;
		}

	}

    // AT: hinzugefügt
    return counter;
}

int pruefeObenLinks(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip)
{
	int counter = 0;

	for (int i = 1; i < 4; i++)
	{
		if (letzterPunkt.spalte - i >= 1 && letzterPunkt.zeile + i <= 7)
		{
			if (chip == spielfeld.getPunkt(letzterPunkt.zeile + i, letzterPunkt.spalte - i))
			{
				counter++;
				continue;
			}
			else
				return counter;
		}

	}

    // AT: hinzugefügt
    return counter;

}

int pruefeUntenRechts(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip)
{
	int counter = 0;

	for (int i = 1; i < 4; i++)
	{
		if (letzterPunkt.spalte + i >= 1 && letzterPunkt.zeile - i <= 7)
		{
			if (chip == spielfeld.getPunkt(letzterPunkt.zeile - i, letzterPunkt.spalte + i))
			{
				counter++;
				continue;
			}
			else
				return counter;
		}

	}

    // AT: hinzugefügt
    return counter;
}

int pruefeObenRechts(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip)
{
	int counter = 0;

	for (int i = 1; i < 4; i++)
	{
		if (letzterPunkt.spalte + i >= 1 && letzterPunkt.zeile + i <= 7)
		{
			if (chip == spielfeld.getPunkt(letzterPunkt.zeile + i, letzterPunkt.spalte + i))
			{
				counter++;
				continue;
			}
			else
				return counter;
		}

	}

    // AT: hinzugefügt
    return counter;
}

int pruefeUntenLinks(const SpielfeldT& spielfeld, const Punkt& letzterPunkt, const Chip& chip)
{
	int counter = 0;

	for (int i = 1; i < 4; i++)
	{
		if (letzterPunkt.spalte - i >= 1 && letzterPunkt.zeile - i <= 7)
		{
			if (chip == spielfeld.getPunkt(letzterPunkt.zeile - i, letzterPunkt.spalte - i))
			{
				counter++;
				continue;
			}
			else
				return counter;
		}

	}

    // AT: hinzugefügt
    return counter;
}



bool istUnentschieden(const SpielfeldT& spielfeld)
{

    // AT: 1 bis 7 nicht 0 bis 6
	for (int i = 1; i <= 7; i++)
	{

        // AT: nicht 'leer' sondern leer
        if (spielfeld.getPunkt(i, 6) == leer)
		{
			return false;
		}
	}
	return true;
}