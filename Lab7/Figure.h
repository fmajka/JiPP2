//
// Created by Franek on 22.10.2021.
//

#include <iostream>
#include <string.h>

using namespace std;

#ifndef DZIEDZICZENIE_FIGURE_H
#define DZIEDZICZENIE_FIGURE_H


class Figure {
protected:
    string nazwa;
    string kolor;
public:
    //Figure(string n, string k);

    void printInfo();
    virtual double getArea() = 0;
};

class Square : public Figure{
protected:
    double a;
public:
    Square(double a, string k);
    void setA(double a);
    double pole();
    double obwod();

    virtual double getArea();
};

class Circle : public Figure{
protected:
    double r;
public:
    Circle(double r, string k);
    void setR(double r);
    double pole();
    double obwod();

    virtual double getArea();
};

class Rectangle : public Figure{
protected:
    double a, b;
public:
    Rectangle(double a, double b, string k);
    void setAB(double a, double b);
    double pole();
    double obwod();

    virtual double getArea();
};


#endif //DZIEDZICZENIE_FIGURE_H
