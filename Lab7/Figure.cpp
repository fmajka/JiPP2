//
// Created by Franek on 22.10.2021.
//

#include "Figure.h"

void Figure::printInfo(){
    cout << "Figura " << this->nazwa << ", kolor: " << this->kolor << endl;
}
/*Figure::Figure(string n, string k){
    this->nazwa = n;
    this->kolor = k;
}*/

void Square::setA(double a){
    this->a = a;
}
double Square::pole(){
    return a*a;
}
double Square::obwod(){
    return 4*a;
}
Square::Square(double a, string k){
    this->nazwa = "kwadrat";
    this->kolor = k;
    this->a = a;
}
double Square::getArea() {
    return a*a;
}

void Circle::setR(double r){
    this->r = r;
}
double Circle::pole(){
    return 3.14*r*r;
}
double Circle::obwod(){
    return 2*3.14*r;
}
Circle::Circle(double r, string k){
    this->nazwa = "kolo";
    this->kolor = k;
    this->r = r;
}
double Circle::getArea() {
    return 3.14*r*r;
}

void Rectangle::setAB(double a, double b){
    this->a = a;
    this->b = b;
}
double Rectangle::pole(){
    return a*b;
}
double Rectangle::obwod(){
    return 2*a + 2*b;
}
Rectangle::Rectangle(double a, double b, string k){
    this->nazwa = "prostokat";
    this->kolor = k;
    this->a = a;
    this->b = b;
}
double Rectangle::getArea() {
    return a*b;
}