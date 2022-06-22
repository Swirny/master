#include <iostream>
#include <string>
#include <cmath>
#include "Spieler.h"
#include "Mensch.h"
#include "SpielfeldT.h"
#include "gewinnauswertung.h"
#include "Computer.h"

using namespace std;

enum modus { spielerPc, spieler2, pc2 }; //spieler2 = spieler v spieler,pc2 = pc v pc

modus selectMode(SpielfeldT* feld);

bool PlayAgain(SpielfeldT* feld);

void play(Spieler* spielerArray[], SpielfeldT* feld);


int main()
{
    // AT: Initialisierung mit nullptr
    Spieler* spielerArray[2] = { nullptr, nullptr };
	
    //Spielmodus
	SpielfeldT* feld = new SpielfeldT();

    // AT: clearSpielfeld hinzugefügt
    feld->clearSpielfeld();

    modus spielModus = selectMode( feld);
	
	switch (spielModus)
	{
	case(spielerPc):
		spielerArray[0] = new Mensch(gelb, feld);
		spielerArray[1] = new Computer(rot, "Computer", feld);
		do
		{
			play(spielerArray,feld);
			
		} while (PlayAgain(feld));

		break;
	case(spieler2):
		spielerArray[0] = new Mensch(gelb, feld) ;
		spielerArray[1] = new Mensch(rot, feld) ;
		do
		{
			play(spielerArray,feld);

		} while (PlayAgain(feld));
		break;
	case(pc2):
        // AT: auskommentiert
		//Computer puter1();
		//Computer puter2();
		spielerArray[0] = new Computer(gelb,"Computer1", feld);
		spielerArray[1] = new Computer(rot, "Computer2", feld);
		do
		{
			play(spielerArray,feld);

		} while (PlayAgain(feld));
		break;
	default:
		break;

	}

    // AT: if-Anweisung hinzugefügt
    if (spielerArray[0] != nullptr)
    	delete spielerArray[0];
    if (spielerArray[1] != nullptr)
        delete spielerArray[1];
	
	return 0;
}

modus selectMode(SpielfeldT* feld)//auf spielfeld ausgeben
{
	int auswahl = 0;
	
	feld->drawInfo("Bitte Spielmodus auswaehlen: \n 1: Spieler vs Computer \n 2: Spieler vs Spieler \n 3: Computer vs Computer \n Ihre Auswahl: ");
	auswahl = feld->getIntInput();
	if(auswahl < 4)
	{
		auswahl--;
		return modus(auswahl);
	}
	else
	{
        // AT: return hinzugefügt
		return selectMode(feld);
	}
	
} 

bool PlayAgain(SpielfeldT* feld)
{
	feld->drawInfo("Wollen Sie erneut spielen? (J/j für erneutes Spielen): ");
	string replay;
	replay=feld->getStringInput();
	if (replay == "J" || replay == "j")
	{
		return true;
	}
	else
	{
		return false;
	}
}

	void play(Spieler* spielerArray[], SpielfeldT* feld)
	{
		int currentPlayer = rand() % 2;
        // AT: Initialisierung der lokalen Variable
        Punkt currentPunkt = { 0,0 };
		do
		{
			currentPunkt = spielerArray[currentPlayer]->naechsterZug();
			currentPlayer++;
			currentPlayer = currentPlayer % 2;
		}while (!ueberpruefeGewinner(*feld, currentPunkt) || !istUnentschieden(*feld));//Nicht Unentschieden und Nicht Gewonnen
		if(istUnentschieden(*feld))
		{
			feld->drawInfo("Unentschieden!");
		}
		else
		{
			string output = spielerArray[currentPlayer]->getName() + " hat gewonnen!";
			feld->drawInfo(output);
		}
		
	}
