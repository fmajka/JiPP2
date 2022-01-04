//
// Created by Franek on 04.01.2022.
//
#include <iostream>
#include <vector>

#ifndef LAB10_1_CSVLIB_H
#define LAB10_1_CSVLIB_H


class csvLib {
    std::string path;
    char separator;
    std::vector<std::string> content;
public:
    //tworzy nowy obiekt do obslugi baz
    //przekazywane argumenty: sciezka pliku, separator (domyslnie przecinek)
    csvLib(std::string, char = ',');

    //wczytuje dane z pliku o sciezce path
    void read();

    //zapisuje dane do pliku o sciezce path
    //opcjonalnie edytuje aktualna sciezke do podana w argumencie
    void write(std::string = "");
};


#endif //LAB10_1_CSVLIB_H
