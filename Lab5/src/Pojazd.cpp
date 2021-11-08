//
// Created by Franek on 08.11.2021.
//

#include "../include/Pojazd.h"

//normalny konstruktor
Pojazd::Pojazd(string numerRejestracyjny, string nazwa, int iloscMiejsc, string markaTyp){
    this->numerRejestracyjny = numerRejestracyjny;
    this->nazwa = nazwa;
    this->iloscMiejsc = iloscMiejsc;
    this->markaTyp = markaTyp;
    this->pasazer = new string[iloscMiejsc];
    for(int i=0; i<iloscMiejsc; i++)
        pasazer[i] = "puste";

    this->zainstalowanaWersjaOprogramowania = "v1.0";   //domyslna wersja oprogramowania
}

//konstruktor kopiujacy
Pojazd::Pojazd(Pojazd &pojazd){
    this->numerRejestracyjny = pojazd.numerRejestracyjny;
    this->nazwa = pojazd.nazwa;
    this->iloscMiejsc = pojazd.iloscMiejsc;
    this->markaTyp = pojazd.markaTyp;
    this->pasazer = new string[this->iloscMiejsc];
    for(int i=0; i<this->iloscMiejsc; i++)
        pasazer[i] = pojazd.pasazer[i];

    this->zainstalowanaWersjaOprogramowania = pojazd.zainstalowanaWersjaOprogramowania;
}

string Pojazd::najnowszaWersjaOprogramowania = "v1.3.37";

//wyswietla informacje o pojezdzie
void Pojazd::printInfo(){
    cout << "Pojazd " << this->nazwa << " o numerze rejestracyjnym " << this->numerRejestracyjny << ", marki " << this->markaTyp << " o ilosci miejsc: " << this->iloscMiejsc << endl;
    //cout << "Ilosc miejsc: " << this->iloscMiejsc << endl;
    cout << "Informacje o pasazerach: " << endl;
    for(int i=0; i<this->iloscMiejsc; i++)
        cout << i << ". " << pasazer[i] << endl;
}

//zmienia dane pasazera w danym miejscu na podane
void Pojazd::zmienPasazera(int miejsce, string info) {
    if(miejsce >= iloscMiejsc){
        cout << "Podane miejsce wykracza poza wymiary samochodu!" << endl;
        return;
    }

    this->pasazer[miejsce] = info;
}

//gettery
string Pojazd::getNumerRejestracyjny() {
    return this->numerRejestracyjny;
}

string Pojazd::getNazwa() {
    return this->nazwa;
}

string Pojazd::getMarkaTyp() {
    return this->markaTyp;
}

//settery
void Pojazd::setNumerRejestracyjny(string nowy) {
    this->numerRejestracyjny = nowy;
}

void Pojazd::setNazwa(string nowa) {
    this->nazwa = nowa;
}

//2.3 zadania
string Pojazd::getOprogramowanie() {
    return this->zainstalowanaWersjaOprogramowania;
}

void Pojazd::aktualizujOprogramowanie() {
    this->zainstalowanaWersjaOprogramowania = najnowszaWersjaOprogramowania;
}

void Pojazd::opublikujNoweOprogramowanie(string wersja) {
    Pojazd::najnowszaWersjaOprogramowania = wersja;
}