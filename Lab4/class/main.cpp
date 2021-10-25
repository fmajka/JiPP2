#include <iostream>
#include "Prostopadloscian.h"
#include "Kula.h"
#include "FunkcjaKwadratowa.h"
#include "Student.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    //zadanie 1
    Prostopadloscian prostopadloscian;

    prostopadloscian.set(4, 6, 8);
    cout << "Pole powierzchni prostopadloscianu wynosi " << prostopadloscian.pole() << endl;

    //zadanie 2
    Kula kula;

    kula.set(5);
    cout << "Objetosc kuli wynosi " << kula.objetosc() << endl;

    //zadanie 3
    FunkcjaKwadratowa funkcjaKwadratowa;

    funkcjaKwadratowa.set(4, 6, 1);
    funkcjaKwadratowa.wyswietl();

    //zadanie 4
    Student student;

    student.wczytaj("Arkadiusz", "Arkowski", 123654, 32, 13);
    double poprawnosc = student.poprawnosc() * 100;
    cout << "Poprawnosc studenta " << student.getName() << " " << student.getSur() << " wynosi " << poprawnosc << "%" << endl;

    return 0;
}
