//
// Created by Franek on 18.10.2021.
//

#include <iostream>
#include <ctime>
#define SIZEDEF 100

using namespace std;

//Z1: liczy pole prostokata o bokach 'a' i 'b' dla 2 parametrów...
double pole (double a, double b){
    return a*b;
}
//...lub pole trapezu o podstawach 'a', 'b' i wysokosci 'h' dla 3 parametrów
double pole (double a, double b, double h){
    return (a+b)*h/2;
}

//Z2.1: zwraca losowa liczbe calkowita miedzy 'a' i 'b'
int zwrocLosowa(int a, int b){
    return rand()%(b-a+1) + a;
}

//Z2.2: zwraca najwieksza liczbe ze wszystkich zgromadzonych w tablicy
int zwrocNajwieksza(int tab[], int size){
    int najw = tab[0];
    for(int i=0; i<size; i++){
        if(tab[i] > najw)
            najw = tab[i];
    }
    return najw;
}

//Z2.3: odwraca tablice
int zamiana(int tab[], int size){
    for(int i=0; i<size/2; i++){
        swap(tab[i], tab[size-i-1]);
    }
}

//Z3.1: liczy srednia z wartosci zmiennych wskazywanych przez wskazniki
double srednia(double *a, double *b){
    return (*a + *b) / 2;
}

//Z3.2: zwraca true jesli wartosc wskazywanej zmiennej jest wieksza od 0
int wiekszeOdZera(int *wartosc){
    if(*wartosc > 0)
        return true;

    return false;
}

//Z3.3: sortuje tablice rosnaco
void sortujRosnaco(int *tab){

    for(int i=1; i<SIZEDEF; i++){
        int wart = tab[i];
        int j = i - 1;
        while(j >= 0 && tab[j] > wart){
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = wart;
    }
}

//Z3.4: wpisuje do zmiennej wskazywanej przez wskaznik "w" wartosc "x"
void wpiszDoZmiennej(int x, int *w){
    *w = x;
}


void zadanie1();
void zadanie2();
void zadanie3();
void zadanie4();


int main(){
    //zadanie1();
    //zadanie2();
    //zadanie3();
    zadanie4();
}


void zadanie1(){
    cout << "Zadanie 1" << endl;
    cout << pole(2,3, 4) << endl;
}


void zadanie2(){

    //z2.1
    cout << "Zadanie 2.1" << endl;

    int losowaMin = 4, losowaMax = 8;
    srand(time(NULL));
    cout << "Wylosowana wartosc miedzy " << losowaMin << " a " << losowaMax << ": " << zwrocLosowa(losowaMin, losowaMax) << endl;


    //z2.2
    cout << "Zadanie 2.2" << endl;

    int *tab = new int[SIZEDEF];
    for(int i=0; i<SIZEDEF; i++){
        tab[i] = zwrocLosowa(1, 100);
        cout << tab[i] << ", ";
    }
    cout << endl;

    cout << "Najw: " << zwrocNajwieksza(tab, SIZEDEF) << endl;


    //z2.3
    cout << "Zadanie 2.3" << endl;

    zamiana(tab, SIZEDEF);
    cout << "Po zamianie: " ;
    for(int i=0; i<SIZEDEF; i++){
        cout << tab[i] << ", ";
    }
    cout << endl;
}


void zadanie3(){

    //z3.1
    cout << "Zadanie 3.1" << endl;

    double a, b;
    cout << "Podaj pierwsza liczbe: ";
    cin >> a;
    cout <<  "Podaj druga liczbe: ";
    cin >> b;
    cout << "Srednia liczb a i b: " << srednia(&a, &b) << endl;


    //z3.2
    cout << "Zadanie 3.2" << endl;

    int *tab2 = new int[SIZEDEF];
    for(int i=0; i<SIZEDEF; i++){
        tab2[i] = zwrocLosowa(-10, 10);
        cout << tab2[i] << ", ";
    }
    cout << endl;

    //pokaz wartosci wieksze od 0
    cout << "Wypisane wartosci wieksza od 0: ";
    for(int i=0; i<SIZEDEF; i++){
        if(wiekszeOdZera(&tab2[i]))
            cout << tab2[i] << ", ";
    }
    cout << endl;


    //z3.3
    cout << "Zadanie 3.3" << endl;

    int *tab3 = new int[SIZEDEF];
    cout << "Przed posortowaniem: ";
    for(int i=0; i<SIZEDEF; i++){
        tab3[i] = zwrocLosowa(1, 100);
        cout << tab3[i] << ", ";
    }
    cout << endl;

    sortujRosnaco(tab3);
    cout << "Po posortowaniu: ";
    for(int i=0; i<SIZEDEF; i++){
        cout << tab3[i] << ", ";
    }
    cout << endl;


    //z3.4
    cout << "Zadanie 3.4" << endl;

    int cel, wartosc;
    cout << "Podaj wartosc do przekazania przez wskaznik: ";
    cin >> wartosc;

    wpiszDoZmiennej(wartosc, &cel);
    cout << "Wartosc celu wynosi teraz " << cel << endl;
}


void zadanie4(){

    //z4.1
    cout << "Zadanie 4.1" << endl;

    try{
        int a, b;
        cout << "Podaj dzielna: ";
        cin >> a;
        cout << "Podaj dzielnik: ";
        cin >> b;

        if(b == 0)
            throw("Nie mozna dzielic przez 0!");
        else if(a < 0 || b < 0)
            throw("Co najmniej jedna z podanych wartosci nie jest liczba naturalna!");
        else if(a % b != 0)
            throw("Wynikiem dzelenia bylby ulamek!");
        else
            cout << a << " / " << b << " = " << a/b << endl;

    }
    catch(const char *msg){
        cout << msg << endl;
    }


    //z4.2
    cout << "Zadanie 4.2" << endl;

    try{
        char *str;
        cout << "Podaj ciag: ";
        cin >> str;

        int val = 0;
        for(int i=0; str[i] != '\0'; i++){
            if(str[i] < '0' || str[i] > '9')
                throw("Wykryto niewlasciwy znak!");
            if(val > 214748364 || (val == 214748364 && str[i] > '7'))
                throw("Podana liczba jest zbyt duza!");

            val *= 10;              //"przesuwa" cyfry o 1 pole do przodu
            val += str[i] - '0';    //zwieksza wartosc o kolejna cyfre
        }
        cout << "Liczba po konwersji: " << val << endl;
    }
    catch(const char *msg){
        cout << msg << endl;
    }
}