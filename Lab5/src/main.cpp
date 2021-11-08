//
// Created by filip on 07.11.2021.
//

#include <iostream>
#include "../include/Point.h"
#include "../include/Pojazd.h"

using namespace std;

void zadania1(Pojazd &p1);
void zadania2(Pojazd &p1);

int main() {
    {
        /*
        Point p1("P1"), p2(5, 5, "P2");

        cout << "Initial values" << endl;
        p1.printData();
        p2.printData();

        cout << endl << "Create copy of point" << endl;
        Point p1c(p1), p2c(p2);
        //Update copied points names
        p1c.setName("P1c");
        p2c.setName("P2c");

        cout << "Values after copying" << endl;
        p1.printData();
        p2.printData();
        p1c.printData();
        p2c.printData();

        cout << endl << "Update P1 and P2 x and y (increase 10)" << endl;
        p1.setX(10);
        p1.setY(10);
        p2.setX(15);
        p2.setY(15);

        cout << "Values after update values" << endl;
        p1.printData();
        p2.printData();
        p1c.printData();
        p2c.printData();
         */


        //tworzy nowy pojazd
        Pojazd p1("RT 1337", "Samochodzik", 4, "Renault Jakis-tam");

        //1.2 zadania
        zadania1(p1);

        //2.3 zadania
        zadania2(p1);

    }

    cout << "End program" << endl;

    return 0;
}

void zadania1(Pojazd &p1){
    cout << "1.2 zadania" << endl;

    p1.printInfo();
    //zmienia dane pasazera
    p1.zmienPasazera(2, "Daelin Proudmoore");
    p1.printInfo();

    //kopiuje wczesniej stworzony pojazd
    cout << "Kopia pojazdu:" << endl;
    Pojazd p1c(p1);
    p1c.printInfo();

    //zmienia nazwe samochodu i sprawdza ja
    cout << "Zmien i sprawdz nazwe samochodu p1" << endl;
    p1.setNazwa("Potezny samochod");
    cout << "Nowa nazwa: " << p1.getNazwa() << endl;
}

void zadania2(Pojazd &p1){
    cout << "2.3 zadania" << endl;

    int stala1a = 314;
    const int *point1 = &stala1a;
    //*point1 = 628;     //blad - nie mozna zmienic wartosci stalej wskazywanej przez wskaznik
    const int stala1b = 666;
    point1 = &stala1b;

    int zmienna2a = 314;
    int *const point2 = &zmienna2a;
    *point2 = 628;
    int zmienna2b = 666;
    //point2 = &zmienna2;   //blad - nie mozna przypisac nowej wartosci do stalego wskaznika

    int zmienna3 = 314;
    const int* const youCantModifyMe = &zmienna3;   //po zadeklarowaniu nie mozna tu nic zmienic
    //youCantModifyMe = &zmienna2a; //blad
    //*youCantModifyMe = 300;   //tez blad

    //oprogramowanie pojazdu
    cout << "Domyslne oprogramowanie: " << p1.getOprogramowanie() << endl;
    p1.aktualizujOprogramowanie();
    cout << "Oprogramowanie po aktualizacji: " << p1.getOprogramowanie() << endl;
    Pojazd::opublikujNoweOprogramowanie("v1.6.66");
    p1.aktualizujOprogramowanie();
    cout << "Oprogramowanie po aktualizacji na nowo opublikowane: " << p1.getOprogramowanie() << endl;
}