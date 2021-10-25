//
// Created by Franek on 25.10.2021.
//

#include <math.h>
#include "Punkt.h"

Punkt::Punkt(double tX, double tY)
: x(tX), y(tY)
{

}

double Punkt::odleglosc(Punkt cel) {
    double dx = this->x - cel.x;
    double dy = this->y - cel.y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}