//
// Created by Franek on 18.10.2021.
//

#ifndef VECTOR_IMAGINARY_H
#define VECTOR_IMAGINARY_H


class Imaginary {
private:
    double re, im;

public:
    Imaginary() {};

    Imaginary(double re, double im) : re(re), im(im) {}

    void print();

    Imaginary operator+(const Imaginary &rhs) const;
    Imaginary operator+=(const Imaginary &rhs);

    Imaginary operator-(const Imaginary &rhs) const;
    Imaginary operator-=(const Imaginary &rhs);

    Imaginary operator*(const Imaginary &rhs) const;
    Imaginary operator*=(const Imaginary &rhs);

    Imaginary operator/(const Imaginary &rhs) const;
    Imaginary operator/=(const Imaginary &rhs);
};


#endif //VECTOR_IMAGINARY_H
