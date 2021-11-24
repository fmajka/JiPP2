#include <iostream>
#include "Figure.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    cout << "Dziedziczenie:" << endl;
    Square *f1 = new Square(5, "czerwony");
    f1->printInfo();
    cout << "Pole=" << f1->pole() << ", obwod=" << f1->obwod() << endl;
    Circle *f2 = new Circle(4, "zielony");
    f2->printInfo();
    cout << "Pole=" << f2->pole() << ", obwod=" << f2->obwod() << endl;
    Rectangle *f3 = new Rectangle(4,6,"niebieski");
    f3->printInfo();
    cout << "Pole=" << f3->pole() << ", obwod=" << f3->obwod() << endl;

    cout << endl << "Polimorfizm: " << endl;
    Figure *circle = new Circle(5, "");
    Figure *rectangle = new Rectangle(5, 18, "");
    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;

    return 0;

}
