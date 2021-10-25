#include <iostream>
#include <string.h>

using namespace std;

struct samochod{
    char marka[20];
    char model[20];
    int rokProdukcji;
    char kolor[20];
}cars[] = {
        {"Renault", "m1", 1999, "czerwony"},
        {"Opel", "m2", 2001, "bialy"},
        {"Taro", "LOTAR", 2004, "zielony"},
        {"Taro", "ch4", 2014, "rozowy"}
};

//zadanie 1
void zadanie1(){

    int liczbaAut = 4;

    cout << "Marka\t" << "Model\t" << "Rok\t" << "Kolor" << endl;
    for(int i=0; i<liczbaAut; i++){
        cout << cars[i].marka << "\t" << cars[i].model << "\t" << cars[i].rokProdukcji << "\t" << cars[i].kolor << endl;
    }

}


//zadanie 2
void zadanie2(){

    struct samochod2{
        char marka[20];
        char model[20];
        int rokProdukcji;
        char kolor[20];
        int iloscMiejsc;
    };

    int liczbaAut = 4;
    samochod2 cars[] = {
            {"Renault", "m1", 1999, "czerwony", 5},
            {"Opel", "m2", 2001, "bialy", 5},
            {"Taro", "LOTAR", 2004, "zielony", 4},
            {"Taro", "ch4", 2014, "rozowy", 6}
    };

    cout << "Marka\t" << "Model\t" << "Rok\t" << "Kolor\t" << "Ilosc miejsc" << endl;
    for(int i=0; i<liczbaAut; i++){
        cout << cars[i].marka << "\t" << cars[i].model << "\t" << cars[i].rokProdukcji << "\t" << cars[i].kolor << "\t" << cars[i].iloscMiejsc << endl;
    }

}

int liczbaMarki(samochod samochody[], int ilosc, int *index){
    int maxIlosc = 1;
    int lastIlosc = 1;
    *index = 0;
    for(int i=0; i<ilosc-1; i++){
        for(int j=i+1; j<ilosc; j++){
            if(!strcmp(samochody[i].marka, samochody[j].marka))
                lastIlosc++;
        }
        if(lastIlosc > maxIlosc) {
            *index = i;
            maxIlosc = lastIlosc;
        }
        lastIlosc = 1;
    }

    return maxIlosc;
}

//zadanie 3
void zadanie3(){
    int index;
    int ilosc = liczbaMarki(cars, 4, &index);
    cout << "Ilosc samochodow marki " << cars[index].marka << ": " <<  ilosc << endl;
}


int rokNajnizszy(samochod[], int);

//zadanie 4
void zadanie4(){
    cout << "Rok produkcji najstarszego samochodu: " << rokNajnizszy(cars, 4) << endl;
}

int rokNajnizszy(samochod samochody[], int ilosc){
    int minRok = samochody[0].rokProdukcji;
    for(int i=1; i<ilosc; i++){
        if(samochody[i].rokProdukcji < minRok)
            minRok = samochody[i].rokProdukcji;
    }

    return minRok;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    zadanie1();
    zadanie2();
    zadanie3();
    zadanie4();

    return 0;
}
