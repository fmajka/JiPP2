//
// Created by Franek on 25.10.2021.
//

#include <iostream>
#include "FunkcjaKwadratowa.h"

void FunkcjaKwadratowa::wyswietl() {
    std::cout << "f(x) = " << this->a << " x^2 + " << this->b << " x + " << this->c << std::endl;
}

void FunkcjaKwadratowa::set(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

double FunkcjaKwadratowa::getA(){
    return this->a;
}

double FunkcjaKwadratowa::getB(){
    return this->b;
}

double FunkcjaKwadratowa::getC(){
    return this->c;
}