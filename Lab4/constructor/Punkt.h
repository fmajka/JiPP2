//
// Created by Franek on 25.10.2021.
//

#ifndef CONSTRUCTOR_PUNKT_H
#define CONSTRUCTOR_PUNKT_H


class Punkt {
public:
    double x;
    double y;

    Punkt(double, double);
    double odleglosc(Punkt cel);
};


#endif //CONSTRUCTOR_PUNKT_H
