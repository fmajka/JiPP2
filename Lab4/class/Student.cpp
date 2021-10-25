//
// Created by Franek on 25.10.2021.
//

#include <iostream>
#include "Student.h"

void Student::wczytaj(const char *imie, const char *nazwisko, int numerAlbumu, int liczbaPytan, int poprawneOdpowiedzi){
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->numerAlbumu = numerAlbumu;
    this->liczbaPytan = liczbaPytan;
    this->poprawneOdpowiedzi = poprawneOdpowiedzi;
}

double Student::poprawnosc() {
    std::cout << "Liczenie poprawnosci dla studenta " << this->imie << " " << this->nazwisko << std::endl;
    return (double)poprawneOdpowiedzi / (double)liczbaPytan;
}

const char *Student::getName(){
    return this->imie;
}

const char *Student::getSur(){
    return this->nazwisko;
}

int Student::getNumber(){
    return this->numerAlbumu;
}

int Student::getQuestions(){
    return this->liczbaPytan;
}

int Student::getCorrectAnswers(){
    return this->poprawneOdpowiedzi;
}