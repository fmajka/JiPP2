//
// Created by Franek on 08.11.2021.
//

#ifndef EXAMPLE_POJAZD_H
#define EXAMPLE_POJAZD_H

#include <iostream>

using namespace std;

class Pojazd {
private:
    string numerRejestracyjny;
    string nazwa;
    int iloscMiejsc;
    string *pasazer;
    string markaTyp;

    string zainstalowanaWersjaOprogramowania;
    static string najnowszaWersjaOprogramowania;

public:
    Pojazd(string numerRejestracyjny, string nazwa, int iloscMiejsc, string markaTyp);
    Pojazd(Pojazd &pojazd);

    void printInfo();

    void zmienPasazera(int miejsce, string info);

    string getNumerRejestracyjny();
    string getNazwa();
    string getMarkaTyp();

    void setNumerRejestracyjny(string nowy);
    void setNazwa(string nowa);

    //2.3 zadania
    string getOprogramowanie();
    void aktualizujOprogramowanie();

    static void opublikujNoweOprogramowanie(string wersja);
};


#endif //EXAMPLE_POJAZD_H
