//
// Created by Franek on 25.10.2021.
//

#ifndef CLASS_STUDENT_H
#define CLASS_STUDENT_H


class Student {
    const char *imie;
    const char *nazwisko;
    int numerAlbumu;
    int liczbaPytan;
    int poprawneOdpowiedzi;

public:
    void wczytaj(const char*, const char*, int, int, int);
    double poprawnosc();
    const char *getName();
    const char *getSur();
    int getNumber();
    int getQuestions();
    int getCorrectAnswers();
};


#endif //CLASS_STUDENT_H
