//
// Created by Franek on 25.10.2021.
//

#include "Prostopadloscian.h"

double Prostopadloscian::pole() {
    return 2*(a * b + a * h + b * h);
}

void Prostopadloscian::set(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->h = c;
}

double Prostopadloscian::getA(){
    return this->a;
}

double Prostopadloscian::getB(){
    return this->b;
}

double Prostopadloscian::getH(){
    return this->h;
}
