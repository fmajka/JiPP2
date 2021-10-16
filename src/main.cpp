#include <iostream>
#include <string.h>
#include "../include/simpleCalc.h"

using namespace std;

int main(int argc, char *argv[])
{
    //error tag
    int error = 0;

    //czy podano rodzaj dzialania?
    if(argc < 2)
        error = 1;
    //dodawanie
    else if (!strcmp(argv[1], "add")) {                        //sprawdz rodzaj dzialania
        if(argc >= 4)                                          //sprawdz, czy podano wystarczajaca ilosc argumentow
            add(atoi(argv[2]), atoi(argv[3]));  //wykonaj dzialanie
        else
            error = 1;                                         //WPR oznacz blad
    }
    //odejmowanie
    else if (!strcmp(argv[1], "subtract")) {
        if(argc >= 4)
            subtract(atoi(argv[2]), atoi(argv[3]));
        else
            error = 1;
    }
    //objetosc
    else if (!strcmp(argv[1], "volume")) {
        if(argc >= 6)
            volume(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
        else
            error = 1;
    }
    //pomoc
    else if (!strcmp(argv[1], "help")) {
        help();
    }
    //podano niewlasciwy rodzaj dzialania
    else error = 1;

    //error message
    if(error){
        cout << "Wystapil blad..." << endl << endl;
        help();
    }

    return 0;
}