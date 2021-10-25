//
// Created by Franek on 25.10.2021.
//

#ifndef CLASS_PROSTOPADLOSCIAN_H
#define CLASS_PROSTOPADLOSCIAN_H


class Prostopadloscian {

    double a;
    double b;
    double h;

public:
    double pole();
    void set(double, double, double);
    double getA();
    double getB();
    double getH();
};


#endif //CLASS_PROSTOPADLOSCIAN_H
