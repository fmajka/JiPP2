//
// Created by Franek on 16.10.2021.
//
#include <iostream>
#include "../include/simpleCalc.h"
using namespace std;

int add(int a, int b){
    int wynik = a + b;
    cout << a << " + " << b << " = " << wynik << endl;
    return wynik;
}

int subtract(int a, int b){
    int wynik = a - b;
    cout << a << " - " << b << " = " << wynik << endl;
    return wynik;
}

int volume(int a, int b, int h, int hp){
    int wynik =  ((a + b) * h / 2) * hp;
    cout << "Objetosc graniastoslupa wynosi " << wynik << endl;
    return wynik;
}

void help(){
    cout << "Prosty kalkulator" << endl;
    cout << "simpleCalc [nazwa dzialania] [paramert1] [parametr2] ..." << "\n\n";
    cout << "Dzialania:" << endl;
    //dodawanie
    cout << "add [a] [b]" << endl;
    cout << "   Dodawanie 2 liczb [a] i [b]" << endl;
    //odejmowanie
    cout << "subtract [a] [b]" << endl;
    cout << "   Wynik odejmowania liczby [a] od liczby [b]" << endl;
    //objetosc graniastoslupa
    cout << "volume [a] [b] [h] [hp]" << endl;
    cout << "   Podaje objetosc graniastoslupa prostego o podstawie trapezu o bokach [a] i [b], wysokosci [h], oraz wysokosci graniastoslupa [hp]" << endl;
    //wyswietlenie dokumentacji
    cout << "help" << endl;
    cout << "   Wyswietla ta dokumentacje" << endl;
}