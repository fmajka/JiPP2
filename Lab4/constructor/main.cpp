#include <iostream>
#include "Punkt.h"
#include "Figura.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    //zadanie 1
    Punkt punkt1(10, 15);
    Punkt punkt2(20, 30);

    cout << "Dystans miedzy punktami wynosi " << punkt1.odleglosc(punkt2) << endl;

    //zadanie 2
    int iloscWierzcholkow = 4;
    Figura figura(iloscWierzcholkow);
    for(int i=0; i<iloscWierzcholkow; i++){
        cout << "Wspolrzedne wierzcholka " << i+1 << " figury wynosza: (" << figura.wierzcholki[i].getX() << ", " << figura.wierzcholki[i].getY() << ")" << endl;
    }

    return 0;
}
