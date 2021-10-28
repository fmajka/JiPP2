#include <iostream>
#include <string.h>
#include "../matrixLib/matrixLib.h"

using namespace std;

//wywoluje dzialania na liczbach calkowitych
void calkowite(const char*);

//wywoluje dzialania na liczbach rzeczywistych
void rzeczywiste(const char*);


int main(int argc, char *argv[]) {

    int iloscDzialan = 9;
    const char* dostepneDzialania[] = {"addMatrix", "subtractMatrix", "multiplyMatrix", "multiplyByScalar", "transpozeMatrix", "powerMatrix", "determinantMatrix", "matrixIsDiagonal", "sortRowsInMatrix"};

    const char* dzialanie;
    if(argc > 1)
       dzialanie  = argv[1];
    else
        dzialanie = "help";

    //sprawdz, czy wybrane dzialanie jest poprawne
    bool poprawne = false;
    for(int i=0; i<iloscDzialan; i++){
        if(!strcmp(dzialanie, dostepneDzialania[i])){
            poprawne = true;
            break;
        }
    }

    //pokaz pomoc
    if(!poprawne){
        help();
        return 0;
    }

    //pokaz wybrana opcje
    cout << "Wybrano opcje: " << dzialanie << endl;

    //czy obliczenia maja byc wykonywane na liczbach calkowitych czy tez rzeczywistych?
    bool intCalc = false;

    char opcja[100];
    cout << "Wpisz \"int\" jesli chcesz aby obliczenia byly wykonywane na liczbach calkowitych" << endl;
    cout << "W przeciwnym razie beda one wykonywane na liczbach rzeczywistych" << endl;
    cin >> opcja;

    if(!strcmp(opcja, "int"))
        calkowite(dzialanie);
    else
        rzeczywiste(dzialanie);

    return 0;
}


//inicjalizacja macierzy int i wywolanie odpowiedniej funkcji
void calkowite(const char *dzialanie){
    //definicja zmiennych przechowujacych ilosci wierszy i kolumn odpowiednich macierzy,
    //wartosci sa zwracane przez funkcje poprzez wskazniki
    int wierszeA, kolumnyA;
    int wierszeB, kolumnyB;

    //dodawanie/odejmowanie/mnozenie 2 macierzy
    if(!strcmp(dzialanie, "addMatrix") || !strcmp(dzialanie, "subtractMatrix") || !strcmp(dzialanie, "multiplyMatrix")){
        int **macierzA = wczytajMacierz(&wierszeA, &kolumnyA);
        int **macierzB = wczytajMacierz(&wierszeB, &kolumnyB);

        int **macierzWynikowa;

        //wybierz odpowiednie dzialanie z 3 mozliwych
        if(!strcmp(dzialanie, "addMatrix"))
            macierzWynikowa = addMatrix(macierzA, macierzB, wierszeA, kolumnyA);
        else if(!strcmp(dzialanie, "subtractMatrix"))
            macierzWynikowa = subtractMatrix(macierzA, macierzB, wierszeA, kolumnyA);
        else
            macierzWynikowa = multiplyMatrix(macierzA, macierzB, wierszeA, kolumnyA, kolumnyB);

        pokazMacierz(macierzWynikowa, wierszeA, kolumnyA);
    }

    //mnozenie przez skalar
    else if(!strcmp(dzialanie, "multiplyByScalar")){
        int **macierzA = wczytajMacierz(&wierszeA, &kolumnyA);
        int scalar;
        cout << "Podaj skalar: ";
        cin >> scalar;

        int **macierzWynikowa = multiplyByScalar(macierzA, wierszeA, kolumnyA, scalar);
        pokazMacierz(macierzWynikowa, wierszeA, kolumnyA);
    }

    //transponowanie macierzy
    else if(!strcmp(dzialanie, "transpozeMatrix")){
        int **macierzA = wczytajMacierz(&wierszeA, &kolumnyA);

        int **macierzWynikowa = transpozeMatrix(macierzA, wierszeA, kolumnyA);
        pokazMacierz(macierzWynikowa, wierszeA, kolumnyA);
    }

    //potegowanie macierzy
    else if(!strcmp(dzialanie, "powerMatrix")){
        int **macierzA = wczytajMacierz(&wierszeA, &kolumnyA);
        int potega;
        cout << "Podaj potege: ";
        cin >> potega;

        int **macierzWynikowa = powerMatrix(macierzA, wierszeA, kolumnyA, potega);
        pokazMacierz(macierzWynikowa, wierszeA, kolumnyA);
    }

    //wyznacznik macierzy
    else if(!strcmp(dzialanie, "determinantMatrix")){
        int **macierzA = wczytajMacierz(&wierszeA, &kolumnyA);

        int wyznacznik = determinantMatrix(macierzA, wierszeA, kolumnyA);
        cout << "Wyznacznik macierzy wynosi " << wyznacznik << endl;
    }

    //czy macierz jest diagonalna?
    else if(!strcmp(dzialanie, "matrixIsDiagonal")){
        int **macierzA = wczytajMacierz(&wierszeA, &kolumnyA);

        bool diagonal = matrixIsDiagonal(macierzA, wierszeA, kolumnyA);
        if(diagonal)
            cout << "Macierz jest diagonalna" << endl;
        else
            cout << "Macierz NIE jest diagonalna" << endl;

    }

    //posortuj wiersze macierzy rosnaco
    else if(!strcmp(dzialanie, "sortRowsInMatrix")){
        int **macierzA = wczytajMacierz(&wierszeA, &kolumnyA);

        sortRowsInMatrix(macierzA, wierszeA, kolumnyA);
        cout << "Macierz posortowana: " << endl;
        pokazMacierz(macierzA, wierszeA, kolumnyA);
    }

    //wyswielta pomoc
    else{
        help();
    }
}


//inicjalizacja macierzy double i wywolanie odpowiedniej funkcji
void rzeczywiste(const char *dzialanie){
    //definicja zmiennych przechowujacych ilosci wierszy i kolumn odpowiednich macierzy,
    //wartosci sa zwracane przez funkcje poprzez wskazniki
    int wierszeA, kolumnyA;
    int wierszeB, kolumnyB;

    //dodawanie/odejmowanie/mnozenie 2 macierzy
    if(!strcmp(dzialanie, "addMatrix") || !strcmp(dzialanie, "subtractMatrix") || !strcmp(dzialanie, "multiplyMatrix")){
        double **macierzA = wczytajMacierzDouble(&wierszeA, &kolumnyA);
        double **macierzB = wczytajMacierzDouble(&wierszeB, &kolumnyB);

        double **macierzWynikowa;

        //wybierz odpowiednie dzialanie z 3 mozliwych
        if(!strcmp(dzialanie, "addMatrix"))
            macierzWynikowa = addMatrix(macierzA, macierzB, wierszeA, kolumnyA);
        else if(!strcmp(dzialanie, "subtractMatrix"))
            macierzWynikowa = subtractMatrix(macierzA, macierzB, wierszeA, kolumnyA);
        else
            macierzWynikowa = multiplyMatrix(macierzA, macierzB, wierszeA, kolumnyA, kolumnyB);

        pokazMacierz(macierzWynikowa, wierszeA, kolumnyA);
    }

    //mnozenie przez skalar
    else if(!strcmp(dzialanie, "multiplyByScalar")){
        double **macierzA = wczytajMacierzDouble(&wierszeA, &kolumnyA);
        double scalar;
        cout << "Podaj skalar: ";
        cin >> scalar;

        double **macierzWynikowa = multiplyByScalar(macierzA, wierszeA, kolumnyA, scalar);
        pokazMacierz(macierzWynikowa, wierszeA, kolumnyA);
    }

    //transponowanie macierzy
    else if(!strcmp(dzialanie, "transpozeMatrix")){
        double **macierzA = wczytajMacierzDouble(&wierszeA, &kolumnyA);

        double **macierzWynikowa = transpozeMatrix(macierzA, wierszeA, kolumnyA);
        pokazMacierz(macierzWynikowa, wierszeA, kolumnyA);
    }

    //potegowanie macierzy
    else if(!strcmp(dzialanie, "powerMatrix")){
        double **macierzA = wczytajMacierzDouble(&wierszeA, &kolumnyA);
        unsigned int potega;
        cout << "Podaj potege: ";
        cin >> potega;

        double **macierzWynikowa = powerMatrix(macierzA, wierszeA, kolumnyA, potega);
        pokazMacierz(macierzWynikowa, wierszeA, kolumnyA);
    }

    //wyznacznik macierzy
    else if(!strcmp(dzialanie, "determinantMatrix")){
        double **macierzA = wczytajMacierzDouble(&wierszeA, &kolumnyA);

        double wyznacznik = determinantMatrix(macierzA, wierszeA, kolumnyA);
        cout << "Wyznacznik macierzy wynosi " << wyznacznik << endl;
    }

    //czy macierz jest diagonalna?
    else if(!strcmp(dzialanie, "matrixIsDiagonal")){
        double **macierzA = wczytajMacierzDouble(&wierszeA, &kolumnyA);

        bool diagonal = matrixIsDiagonal(macierzA, wierszeA, kolumnyA);
        if(diagonal)
            cout << "Macierz jest diagonalna" << endl;
        else
            cout << "Macierz NIE jest diagonalna" << endl;

    }

    //posortuj wiersze macierzy rosnaco
    else if(!strcmp(dzialanie, "sortRowsInMatrix")){
        double **macierzA = wczytajMacierzDouble(&wierszeA, &kolumnyA);

        sortRowsInMatrix(macierzA, wierszeA, kolumnyA);
        cout << "Macierz posortowana: " << endl;
        pokazMacierz(macierzA, wierszeA, kolumnyA);
    }

    //wyswielta pomoc
    else{
        help();
    }
}
