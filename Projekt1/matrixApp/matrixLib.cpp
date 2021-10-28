//
// Created by Franek on 26.10.2021.
//

#include <iostream>
#include <math.h>
#include "../matrixLib/matrixLib.h"

//wyswietla pomoc
void help(){
    std::cout << "===Pomoc===" << std::endl;
    std::cout << "Na poczatku dzialania programu uzytkownik ustala ilosc wierszy i kolumn w danej macierzy, po czym podaje jej kolejne wartosci (idac wierszami)" << std::endl;
    std::cout << "Dostepne dzialania:" << std::endl <<
    "addMatrix - sumowanie 2 macierzy" << std::endl <<
    "subtractMatrix - odejmowanie drugiej z wczytanych macierzy od pierwszej" << std::endl <<
    "multiplyMatrix - przemnazanie przez siebie 2 macierzy" << std::endl <<
    "multiplyByScalar - przemnazanie podanej macierzy przez skalar" << std::endl <<
    "transpozeMatrix - transponowanie podanej macierzy" << std::endl <<
    "powerMatrix - podnoszenie macierzy do podanej potegi" << std::endl <<
    "determinantMatrix - obliczanie wyznacznika podanej macierzy" << std::endl <<
    "matrixIsDiagonal - sprawdza czy podana macierz jest diagonalna (zwraca true/false)" << std::endl <<
    "sortRowsInMatrix - sortuje wiersze podanej macierzy rosnaco" << std::endl;
}

//===INT===

//wczytywanie macierzy (int) przez uzytkownika
int **wczytajMacierz(int *wPointer, int *kPointer){

    std::cout << "===Definiujesz nowa macierz (int)===" << std::endl;

    int wiersze, kolumny;

    std::cout << "Podaj ilosc wierszy macierzy: ";
    std::cin >> wiersze;
    while(std::cin.fail()) {
        std::cout << "Podano niepoprawna wartosc, sproboj ponownie: " << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> wiersze;
    }

    std::cout << "Podaj ilosc kolumn macierzy: ";
    std::cin >> kolumny;
    while(std::cin.fail()) {
        std::cout << "Podano niepoprawna wartosc, sproboj ponownie: " << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> kolumny;
    }

    //zwroc informacje o ilosci wierszy i kolumn do funckji main
    *wPointer = wiersze;
    *kPointer = kolumny;

    //inicjalizacja macierzy o odpowiednich wymiarach
    int **m = new int*[kolumny];
    for(int i = 0; i < kolumny; ++i) {
        m[i] = new int[wiersze];
    }

    //podaj wartosci macierzy
    std::cout << "Podaj wartosci macierzy [" << wiersze << " x " << kolumny << "]" << std::endl;
    for(int j=0; j<wiersze; j++){
         for(int i=0; i<kolumny; i++){
             int wartosc;
             std::cout << "Podaj wartosc dla [wiersz: " << j+1 << ", kolumna: " << i+1 << "] =";
             std::cin >> wartosc;
             while(std::cin.fail()) {
                 std::cout << "Podano niepoprawna wartosc, sproboj ponownie: " << std::endl;
                 std::cin.clear();
                 std::cin.ignore(256,'\n');
                 std::cin >> wartosc;
             }
             m[i][j] = wartosc;
        }
    }

    return m;
}


//tworzy pusta macierz (int) o podanych wymiarach (funkcja pomocnicza dla innych funkcji)
int **stworzMacierz(int wiersze, int kolumny){

    //inicjalizacja macierzy o odpowiednich wymiarach
    int **m = new int*[kolumny];
    for(int i = 0; i < kolumny; ++i) {
        m[i] = new int[wiersze];
    }

    return m;
}

//pokazuje zawartosc macierzy (int)
void pokazMacierz(int **a, int wiersze, int kolumny){
    std::cout << "Macierz [" << wiersze << "x" << kolumny <<"]" << std::endl;
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            std::cout << a[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}

//zwraca podmacierz (int) - przekazana do funkcji macierz nie liczac jednego wiersza oraz jednej kolumny
int **podMacierz(int **a, int rozmiar, int wiersz, int kolumna) {

    //stworz zwracana macierz
    int **podmacierz = stworzMacierz(rozmiar-1, rozmiar-1);
    //liczniki sprawdzanego pola podmacierzu
    int iPod=0, jPod=0;

    //wypelnij podmacierz
    for (int j = 0; j < rozmiar; j++) {
        for (int i = 0; i < rozmiar; i++) {
            //sprawdza, czy dana kolumne nalezy pominac
            if (j != wiersz && i != kolumna) {
                //std::cout << "pm:" << jPod << iPod << " = a:" << j << i << std::endl;
                podmacierz[jPod][iPod] = a[j][i];
                iPod++;
                //przejdz do nastepnego wiersza
                if (iPod == rozmiar - 1) {
                    iPod = 0;
                    jPod++;
                }
            }
        }
    }

    return podmacierz;
}


//1. dodawanie macierzy a i b
int **addMatrix(int **a, int **b, int wiersze, int kolumny){
    //stworz zwracana macierz
    int **suma = stworzMacierz(wiersze, kolumny);

    //sumy odpowiednich wartosci zapisane do nowej macierzy
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            suma[i][j] = a[i][j] + b[i][j];
        }
    }

    return suma;
}

//2. odejmowanie macierzy b od a
int **subtractMatrix(int **a, int **b, int wiersze, int kolumny){
    //stworz zwracana macierz
    int **roznica = stworzMacierz(wiersze, kolumny);

    //roznice odpowiednich wartosci zapisane do nowej macierzy
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            roznica[i][j] = a[i][j] - b[i][j];
        }
    }

    return roznica;
}

//3. mnożenie macierzy a i b
int **multiplyMatrix(int **a, int **b, int wierszeA, int kolumnyA, int kolumnyB){

    //stworz zwracana macierz
    int **iloczyn = stworzMacierz(wierszeA, kolumnyB);

    //iloczyny odpowiednich wartosci zapisane do nowej macierzy
    for(int j=0; j<wierszeA; j++){
        for(int i=0; i<kolumnyB; i++){
            int wartosc = 0;
            for(int n=0; n<kolumnyA; n++){
                wartosc += a[n][j] * b[i][n];
                //std::cout << "+= a:" << n << j << " *  b:" << i << n << std::endl;
            }
            iloczyn[i][j] = wartosc;
            //std::cout << "iloczyn:" << i << j << " = " << wartosc << std::endl;
        }
    }

    return iloczyn;
}

//4. mnożenie macierzy przez skalar
int **multiplyByScalar(int** a, int wiersze, int kolumny, int skalar){

    //stworz zwracana macierz
    int **wynik = stworzMacierz(wiersze, kolumny);

    //kolejne przemnozone wartosci zapisane do wynikowej macierzy
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            wynik[i][j] = a[i][j] * skalar;
        }
    }

    return wynik;
}

//5. transponowanie macierzy
int **transpozeMatrix(int** a, int wiersze, int kolumny){

    //stworz zwracana macierz (zamiana kolumn na wiersze i odwrotnie)
    int **wynik = stworzMacierz(kolumny, wiersze);

    //elementy odpowienich wierszy macierzy a wpisywane do odpowiednich kolumn macierzy wynikowej (i odwrotnie)
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            wynik[j][i] = a[i][j];
        }
    }

    return wynik;
}

//6. potęgowanie macierzy
int **powerMatrix(int** a, int wiersze, int kolumny, unsigned int potega){

    //stworz macierz wynikowa
    int **wynik = stworzMacierz(wiersze, kolumny);

    //kolejne elementy macierzy podnoszone do odpowiedniej potegi
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            wynik[i][j] = pow(a[i][j], potega);
        }
    }

    return wynik;
}

//7. wyznacznik macierzy
int determinantMatrix(int** a, int wiersze, int kolumny){
    try{
        if(wiersze != kolumny) {
            throw ("error: nie mozna policzyc wyznacznika takiej macierzy!");
        }
        else{
            if(wiersze == 1)
                return a[0][0];
            else if(wiersze == 2){
                return (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
            }
            else{
                int wyznacznik = 0, znak = 1;
                for (int i = 0; i < kolumny; i++) {
                    int** mniejszaMacierz = podMacierz(a, kolumny, 0, i);
                    //pokazMacierz(mniejszaMacierz, wiersze-1, kolumny-1);
                    wyznacznik += znak * a[0][i] * determinantMatrix(mniejszaMacierz, wiersze - 1, kolumny - 1);
                    znak *= -1;
                }
                return wyznacznik;
            }
        }
    }
    catch(const char *msg){
        std::cout << msg << std::endl;
    }
}

//8. czy macierz jest diagonalna?
bool matrixIsDiagonal(int** a, int wiersze, int kolumny){

    //sprawdzanie kolejnych wartosci w macierzy
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            if(a[i][j] != 0 && i != j)
                return false;
        }
    }

    return true;
}

//9. zamiana 2 wartosci miejscami
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

//10. sortowanie wiersza
void sortRow(int* tab, int rozmiar){
    for(int i=0; i<rozmiar-1; i++){
        for(int j=i+1; j<rozmiar; j++){
            if(tab[j] < tab[i])
                swap(tab[j], tab[i]);
        }
    }
}

//11. sortowanie rosnąco każdego z wierszy macierzy
void sortRowsInMatrix(int** a, int wiersze, int kolumny){
    for(int j=0; j<wiersze; j++){
        int *row = new int[kolumny];
        for(int i=0; i<kolumny; i++) {
            row[i] = a[i][j];
        }
        sortRow(row, kolumny);
        for(int i=0; i<kolumny; i++) {
            a[i][j] = row[i];
        }
    }
}

//===DOULBE===

//wczytywanie macierzy (double) przez uzytkownika
double **wczytajMacierzDouble(int *wPointer, int *kPointer){

    std::cout << "===Definiujesz nowa macierz (double)===" << std::endl;

    int wiersze, kolumny;

    std::cout << "Podaj ilosc wierszy macierzy: ";
    std::cin >> wiersze;
    while(std::cin.fail()) {
        std::cout << "Podano niepoprawna wartosc, sproboj ponownie: " << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> wiersze;
    }

    std::cout << "Podaj ilosc kolumn macierzy: ";
    std::cin >> kolumny;
    while(std::cin.fail()) {
        std::cout << "Podano niepoprawna wartosc, sproboj ponownie: " << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> kolumny;
    }

    //zwroc informacje o ilosci wierszy i kolumn do funckji main
    *wPointer = wiersze;
    *kPointer = kolumny;

    //inicjalizacja macierzy o odpowiednich wymiarach
    double **m = new double*[kolumny];
    for(int i = 0; i < kolumny; ++i) {
        m[i] = new double[wiersze];
    }

    //podaj wartosci macierzy
    std::cout << "Podaj wartosci macierzy [" << wiersze << " x " << kolumny << "]" << std::endl;
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            double wartosc;
            std::cout << "Podaj wartosc dla [wiersz: " << j+1 << ", kolumna: " << i+1 << "] =";
            std::cin >> wartosc;
            while(std::cin.fail()) {
                std::cout << "Podano niepoprawna wartosc, sproboj ponownie: " << std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> wartosc;
            }
            m[i][j] = wartosc;
        }
    }

    return m;
}

//tworzy pusta macierz (double) o podanych wymiarach (funkcja pomocnicza dla innych funkcji)
double **stworzMacierzDouble(int wiersze, int kolumny){

    //inicjalizacja macierzy o odpowiednich wymiarach
    double **m = new double*[kolumny];
    for(int i = 0; i < kolumny; ++i) {
        m[i] = new double[wiersze];
    }

    return m;
}

//pokazuje zawartosc macierzy (double)
void pokazMacierz(double **a, int wiersze, int kolumny){
    std::cout << "Macierz [" << wiersze << "x" << kolumny <<"]" << std::endl;
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            std::cout << a[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}

//zwraca podmacierz (double) - przekazana do funkcji macierz nie liczac jednego wiersza oraz jednej kolumny
double **podMacierz(double **a, int rozmiar, int wiersz, int kolumna) {

    //stworz zwracana macierz
    double **podmacierz = stworzMacierzDouble(rozmiar-1, rozmiar-1);
    //liczniki sprawdzanego pola podmacierzu
    int iPod=0, jPod=0;

    //wypelnij podmacierz
    for (int j = 0; j < rozmiar; j++) {
        for (int i = 0; i < rozmiar; i++) {
            //sprawdza, czy dana kolumne nalezy pominac
            if (j != wiersz && i != kolumna) {
                //std::cout << "pm:" << jPod << iPod << " = a:" << j << i << std::endl;
                podmacierz[jPod][iPod] = a[j][i];
                iPod++;
                //przejdz do nastepnego wiersza
                if (iPod == rozmiar - 1) {
                    iPod = 0;
                    jPod++;
                }
            }
        }
    }

    return podmacierz;
}

//1. dodawanie macierzy a i b
double **addMatrix(double **a, double **b, int wiersze, int kolumny){
    //stworz zwracana macierz
    double **suma = stworzMacierzDouble(wiersze, kolumny);

    //sumy odpowiednich wartosci zapisane do nowej macierzy
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            suma[i][j] = a[i][j] + b[i][j];
        }
    }

    return suma;
}

//2. odejmowanie macierzy b od a
double **subtractMatrix(double **a, double **b, int wiersze, int kolumny){
    //stworz zwracana macierz
    double **roznica = stworzMacierzDouble(wiersze, kolumny);

    //roznice odpowiednich wartosci zapisane do nowej macierzy
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            roznica[i][j] = a[i][j] - b[i][j];
        }
    }

    return roznica;
}

//3. mnożenie macierzy a i b
double **multiplyMatrix(double **a, double **b, int wierszeA, int kolumnyA, int kolumnyB){

    //stworz zwracana macierz
    double **iloczyn = stworzMacierzDouble(wierszeA, kolumnyB);

    //iloczyny odpowiednich wartosci zapisane do nowej macierzy
    for(int j=0; j<wierszeA; j++){
        for(int i=0; i<kolumnyB; i++){
            int wartosc = 0;
            for(int n=0; n<kolumnyA; n++){
                wartosc += a[n][j] * b[i][n];
                //std::cout << "+= a:" << n << j << " *  b:" << i << n << std::endl;
            }
            iloczyn[i][j] = wartosc;
            //std::cout << "iloczyn:" << i << j << " = " << wartosc << std::endl;
        }
    }

    return iloczyn;
}

//4. mnożenie macierzy przez skalar
double **multiplyByScalar(double** a, int wiersze, int kolumny, double skalar){

    //stworz zwracana macierz
    double **wynik = stworzMacierzDouble(wiersze, kolumny);

    //kolejne przemnozone wartosci zapisane do wynikowej macierzy
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            wynik[i][j] = a[i][j] * skalar;
        }
    }

    return wynik;
}

//5. transponowanie macierzy
double **transpozeMatrix(double** a, int wiersze, int kolumny){

    //stworz zwracana macierz (zamiana kolumn na wiersze i odwrotnie)
    double**wynik = stworzMacierzDouble(kolumny, wiersze);

    //elementy odpowienich wierszy macierzy a wpisywane do odpowiednich kolumn macierzy wynikowej (i odwrotnie)
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            wynik[j][i] = a[i][j];
        }
    }

    return wynik;
}

//6. potęgowanie macierzy
double **powerMatrix(double** a, int wiersze, int kolumny, unsigned int potega){

    //stworz macierz wynikowa
    double **wynik = stworzMacierzDouble(wiersze, kolumny);

    //kolejne elementy macierzy podnoszone do odpowiedniej potegi
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            wynik[i][j] = pow(a[i][j], potega);
        }
    }

    return wynik;
}

//7. wyznacznik macierzy
double determinantMatrix(double** a, int wiersze, int kolumny){
    try{
        if(wiersze != kolumny) {
            throw ("error: nie mozna policzyc wyznacznika takiej macierzy!");
        }
        else{
            if(wiersze == 1)
                return a[0][0];
            else if(wiersze == 2){
                return (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
            }
            else{
                int wyznacznik = 0, znak = 1;
                for (int i = 0; i < kolumny; i++) {
                    double** mniejszaMacierz = podMacierz(a, kolumny, 0, i);
                    //pokazMacierz(mniejszaMacierz, wiersze-1, kolumny-1);
                    wyznacznik += znak * a[0][i] * determinantMatrix(mniejszaMacierz, wiersze - 1, kolumny - 1);
                    znak *= -1;
                }
                return wyznacznik;
            }
        }
    }
    catch(const char *msg){
        std::cout << msg << std::endl;
    }
}

//8. czy macierz jest diagonalna?
bool matrixIsDiagonal(double** a, int wiersze, int kolumny){

    //sprawdzanie kolejnych wartosci w macierzy
    for(int j=0; j<wiersze; j++){
        for(int i=0; i<kolumny; i++){
            if(a[i][j] != 0 && i != j)
                return false;
        }
    }

    return true;
}

//9. zamiana 2 wartosci miejscami
void swap(double& a, double& b){
    int temp = a;
    a = b;
    b = temp;
}

//10. sortowanie wiersza
void sortRow(double* tab, int rozmiar){
    for(int i=0; i<rozmiar-1; i++){
        for(int j=i+1; j<rozmiar; j++){
            if(tab[j] < tab[i])
                swap(tab[j], tab[i]);
        }
    }
}

//11. sortowanie rosnąco każdego z wierszy macierzy
void sortRowsInMatrix(double** a, int wiersze, int kolumny){
    for(int j=0; j<wiersze; j++){
        int *row = new int[kolumny];
        for(int i=0; i<kolumny; i++) {
            row[i] = a[i][j];
        }
        sortRow(row, kolumny);
        for(int i=0; i<kolumny; i++) {
            a[i][j] = row[i];
        }
    }
}