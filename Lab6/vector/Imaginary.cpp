//
// Created by Franek on 18.10.2021.
//

#include "Imaginary.h"
#include <iostream>

void Imaginary::print(){
    if(this->im == 0)
        std::cout << this->re << std::endl;
    else if (this->im > 0)
        std::cout << this->re << " + " << this->im << std::endl;
    else
        std::cout << this->re << " - " << -this->im << std::endl;
}

Imaginary Imaginary::operator+(const Imaginary &rhs) const {
    return {re + rhs.re, im + rhs.im};
}

Imaginary Imaginary::operator+=(const Imaginary &rhs) {
    this->re = this->re + rhs.re;
    this->im = this->im + rhs.im;
    return *this;
}

Imaginary Imaginary::operator-(const Imaginary &rhs) const {
    return {re - rhs.re, im - rhs.im};
}

Imaginary Imaginary::operator-=(const Imaginary &rhs) {
    this->re = this->re - rhs.re;
    this->im = this->im - rhs.im;
    return *this;
}

Imaginary Imaginary::operator*(const Imaginary &rhs) const {
    return {re * rhs.re - im * rhs.im, re * rhs.im + rhs.re * im};
}

Imaginary Imaginary::operator*=(const Imaginary &rhs) {
    this->re = re * rhs.re - im * rhs.im;
    this->im = re * rhs.im + rhs.re * im;
    return *this;
}

Imaginary Imaginary::operator/(const Imaginary &rhs) const{
    Imaginary licznik = Imaginary(this->re, this->im) * Imaginary(rhs.re, -rhs.im);
    Imaginary mianownik = rhs*Imaginary(rhs.re, -rhs.im);
    return {licznik.re / mianownik.re, licznik.im / mianownik.re};
}

Imaginary Imaginary::operator/=(const Imaginary &rhs) {
    Imaginary mianownik = rhs*Imaginary(rhs.re, -rhs.im);
    mianownik.print();
    this->re = (this->re * rhs.re - this->im * -rhs.im);
    this->im = (this->im * rhs.re + this->re * -rhs.im);
    return *this;
}