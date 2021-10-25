//
// Created by Franek on 25.10.2021.
//

#include "Kula.h"
#include <math.h>

double Kula::objetosc() {
    return 4/(double)3 * M_PI * pow(r, 3);
}

void Kula::set(double r) {
    this->r = r;
}

double Kula::getR(){
    return this->r;
}