#include "SpielfeldT.h"
using namespace std;
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


//private
void SpielfeldT::drawClearSpielfeld() {
	SetConsoleTextAttribute(hConsole, 15);
	COORD coord;
	coord.X = 0;
	coord.Y = 2;
	SetConsoleCursorPosition(hConsole, coord);
	cout << "            4 GEWINNT               \n" << endl;

	cout << "          " << "\xc9" << "\xcd" << "\xcb" << "\xcd" << "\xcb" << "\xcd" << "\xcb" << "\xcd" << "\xcb" << "\xcd" << "\xcb" << "\xcd" << "\xcb" << "\xcd" << "\xbb" << endl;
	/*l6*/ cout << "          " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << endl;
	cout << "          " << "\xcc" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xb9" << endl;
	/*l5*/ cout << "          " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << endl;
	cout << "          " << "\xcc" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xb9" << endl;
	/*l4*/ cout << "          " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << endl;
	cout << "          " << "\xcc" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xb9" << endl;
	/*l3*/ cout << "          " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << endl;
	cout << "          " << "\xcc" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xb9" << endl;
	/*l2*/ cout << "          " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << endl;
	cout << "          " << "\xcc" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xce" << "\xcd" << "\xb9" << endl;
	/*l1*/ cout << "          " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << " " << "\xba" << endl;
	cout << "          " << "\xc8" << "\xcd" << "\xca" << "\xcd" << "\xca" << "\xcd" << "\xca" << "\xcd" << "\xca" << "\xcd" << "\xca" << "\xcd" << "\xca" << "\xcd" << "\xbc" << endl;

}
void SpielfeldT::drawPunkt(Chip chip, int spalte, int zeile) {
	COORD coord;
	coord.X = 9+spalte*2;
	coord.Y = 17-zeile*2;
	SetConsoleCursorPosition(hConsole, coord);
	if (chip == rot) {
		SetConsoleTextAttribute(hConsole, 12);
		cout << "\x0f";
	}else if(chip == gelb) {
		SetConsoleTextAttribute(hConsole, 14);
		cout << "\x0f";
	}else {
		cout << " ";
	}
	SetConsoleTextAttribute(hConsole, 15);
}
	

//public

SpielfeldT::SpielfeldT() {
	drawClearSpielfeld();
};

////gibt ein Array [0] bis [5] von Chip enums der übergebenen Spalte x(1-7) aus
//SpielfeldT::getSpalte(int spalte);
//
////gibt ein Array [0] bis [6] von Chip enums der übergebenen Zeile x(1-6) aus
//SpielfeldT::getZeile(int zeile);

//gibt den Chip enum des übergebenen Punktes aus (Spalte 1-7, Zeile 1-6)
Chip SpielfeldT::getPunkt(int spalte, int zeile) const {
	return feld[spalte - 1][zeile - 1];
}

//setzt und zeichnet den übergebenen Chip (enum) an den übergebenen Punkt (Spalte 1-7, Zeile 1-6)
void SpielfeldT::setPunkt(Chip chip, int spalte, int zeile) {
	feld[spalte - 1][zeile - 1] = chip;
	drawPunkt(chip, spalte, zeile);
}

//leert das SpielfeldT (und gibt es aus)
void SpielfeldT::clearSpielfeld() {
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++) {
			feld[i][j] = leer;
		}
	}
	drawClearSpielfeld();
}

void SpielfeldT::drawInfo(string text, int startlinie) {
	if (startlinie < 0) {
		startlinie = startlinie * -1;
	}else if(startlinie == 0) {
		startlinie = 1;
	}
	COORD coord;
	coord.X = 0;
	coord.Y = 19+startlinie;
	SetConsoleCursorPosition(hConsole, coord);
	for (int i = 0; i < 6-startlinie; i++)
	{
		cout << "                                                                                     " << endl;
	}
	SetConsoleCursorPosition(hConsole, coord);
	cout << text;
}

string SpielfeldT::getStringInput() {
	string input;
	cin >> input;
	return input;
}
int SpielfeldT::getIntInput() {
	int input;
	cin >> input;
	return input;
}

//int SpielfeldT::getStringInput(string& var) {
//	cin >> var;
//}
//int SpielfeldT::getIntInput(int& var) {
//	cin >> var;
//}