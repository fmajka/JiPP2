//
// Created by Franek on 26.10.2021.
//

#ifndef PROJEKT1_MATRIXLIB_H
#define PROJEKT1_MATRIXLIB_H

#endif //PROJEKT1_MATRIXLIB_H

//funckja wyswietlajaca pomoc
void help();

//funckje pomocniczne (int)
int **wczytajMacierz(int*, int*);

int **stworzMacierz(int, int);

void pokazMacierz(int **, int, int);

int **podMacierz(int **, int, int, int);


//funkcje pomocnicze (double)
double **wczytajMacierzDouble(int*, int*);

double **stworzMacierzDouble(int, int);

void pokazMacierz(double **, int, int);

double **podMacierz(double **, int, int, int);


//funkcje programu (int)
int **addMatrix(int**, int**, int, int);

int **subtractMatrix(int**, int**, int, int);

int **multiplyMatrix(int**, int**, int, int, int);

int **multiplyByScalar(int**, int, int, int);

int **transpozeMatrix(int**, int, int);

int **powerMatrix(int**, int, int, unsigned int);

int determinantMatrix(int**, int, int);

bool matrixIsDiagonal(int**, int, int);

void swap(int&, int&);

void sortRow(int*, int);

void sortRowsInMatrix(int**, int, int);


//funkcje programu (double)
double **addMatrix(double**, double**, int, int);

double **subtractMatrix(double**, double**, int, int);

double **multiplyMatrix(double**, double**, int, int, int);

double **multiplyByScalar(double**, int, int, double);

double **transpozeMatrix(double**, int, int);

double **powerMatrix(double**, int, int, unsigned int);

double determinantMatrix(double**, int, int);

bool matrixIsDiagonal(double**, int, int);

void swap(double&, double&);

void sortRow(double*, int);

void sortRowsInMatrix(double**, int, int);