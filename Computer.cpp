#include "Computer.h"

#include <chrono>
#include <vector>

#include "gewinnauswertung.h"

Computer::Computer(Chip typ, std::string name, SpielfeldT* spielfeld)
    : Spieler(typ, name, spielfeld)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch();

    // AT: cast auf unsigned int hinzugefügt
    randomEngine = std::mt19937((unsigned int)seed.count());
}

auto Computer::naechsterZug() -> Punkt
{
    // AT: Spalten von 1 bis 7 und Zeilen von 1 bis 6 (nicht 0 bis 6 und 0 bis 5) angepasst

    Chip aktuellerTyp = farbe;
    // Zuerst eigenen SIeg überprüfen, dann Gegner
    for (int i = 0; i < 2; i++)
    {
        // Gehe alle Spalten durch
        for (int spalte = 1; spalte <= spalten; spalte++)
        {
            // Wenn Spalte noch frei
            // AT: Parameterreihenfolge spalte und reihe getauscht 
            if (s->getPunkt(spalte, reihen) == leer)
            {
                // Finde Punkt zum einfügen
                int reihe = reihen;
                while (reihe > 1 && s->getPunkt(spalte, reihe - 1) == leer)
                    reihe--;

                // Probiere zug
                // AT: Parameterreihenfolge spalte und reihe getauscht 
                s->setPunkt(aktuellerTyp, spalte, reihe);
                auto punkt = Punkt{ reihe, spalte };

                // Gib den aktuellen Punkt zurück, wenn Sieg gefunden
                if (ueberpruefeGewinner(*s, punkt))
                {
                    return punkt;
                }

                // Chip wieder entfernen
                // AT: Parameterreihenfolge spalte und reihe getauscht 
                s->setPunkt(leer, spalte, reihe);
            }
        }
        // Im nächsten Durchgang Sieg des Gegners überprüfen
        aktuellerTyp = gelb ? rot : gelb;
    }

    // Freie Spalten identifizieren
    std::vector<int> freieSpalten;
    for (int spalte = 1; spalte <= spalten; spalte++)
    {
        // AT: Parameterreihenfolge spalte und reihe getauscht 
        if (s->getPunkt(spalte, reihen) == leer)
        {
            freieSpalten.push_back(spalte);
        }
    }

    // Zufällige Spalte auswählen
    int spalte = freieSpalten[randomEngine() % freieSpalten.size()];

    // Erste freie Position finden
    int reihe = reihen - 1;
    while (reihe > 0 && s->getPunkt(reihe, spalte) == leer)
        reihe--;

    return Punkt{ reihe, spalte };
}
