//
// Created by Franek on 25.10.2021.
//

#include <iostream>
#include "Figura.h"

Figura::Figura(int ilosc)
:ilosc(ilosc)
{
    wierzcholki = new Wierzcholek[ilosc];
    for(int i=0; i<ilosc; i++){
        double x, y;
        std::cout << "Podaj wspolrzedna x " << i+1 << "-ego wierzcholka: ";
        std::cin >> x;
        std::cout << "Podaj wspolrzedna y " << i+1 << "-ego wierzcholka: ";
        std::cin >> y;
        wierzcholki[i].set(x, y);
    }

}