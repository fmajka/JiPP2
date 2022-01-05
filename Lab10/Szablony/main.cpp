#include <iostream>

#define MAT_W 5
#define MAT_K 4

#define VEC_ALLOC 20

//zadanie 1
//i. min
template <typename T>
T myMin(T a, T b){
    return (a<b)? a : b;
}

//ii. max
template <typename T>
T myMax(T a, T b){
    return (a>b)? a : b;
}

//iii. print array
template <typename T>
void myPrintArray(T *arr, int s){
    for(int i=0; i<s; i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
}

//iv. print matrix
template <typename T>
void myPrintMatrix(T **arr, int w, int k){
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }
}

//zadanie 2 - klasa Array
template<typename type>
class Arr {
private:
    type *array;
    int size;

public:
    Arr( int size ): size(size){
        array = new type[size];

    }

    void fill(){
        for(int i=0; i<size; i++)
            array[i] = i;
    }

    void print(){
        for(int i=0; i<size; i++)
            std::cout << array[i] << ", ";
        std::cout << std::endl;
    }

};

//zadanie 3 - klasa Vector
template<typename type>
class Vec {
private:
    type *array;
    int size;
    int tIndex = 0; //ogon

public:
    Vec(): size(VEC_ALLOC){
        array = new type[size];
    }

    //dodawanie elementu na koniec
    void push(type element){
        if(tIndex >= size){
            //stworz szersza tablice
            type * newArr = new type[size + VEC_ALLOC];
            //przekopiuj zawartosc
            std::copy(array, array+size, newArr);
            //usun stara tablice
            delete array;

            //stara tablica wskazuje teraz na nowa, szersza
            array = newArr;
            size += VEC_ALLOC;
            std::cout << "Vector extended successfully!" << std::endl;
        }
        array[tIndex++] = element;
    }

    //usuwanie elementu z konca
    void pop(){
        if(tIndex == 0){
            std::cout << "Vector is empty!" << std::endl;
            return;
        }
        tIndex--;
    }

    type * getPointer(){
        return array;
    }

    void print(){
        for(int i=0; i<tIndex; i++)
            std::cout << array[i] << ", ";
        std::cout << std::endl;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;

    using namespace std;

    cout << "min: " << myMin<int>(3,7) << endl;
    cout << "max: " << myMax<int>(3,7) << endl;

    char tab[5] =  "taro";
    myPrintArray<char>(tab, 5);

    //def matrix
    int **mat =  new int*[MAT_W];
    for(int i=0; i<MAT_W; i++)
        mat[i] = new int[MAT_K];
    //fill matrix
    for(int i=0; i<MAT_W; i++)
        for(int j=0; j<MAT_K; j++)
            mat[i][j] = i*MAT_K+j;
    //print matrix
    myPrintMatrix<int>(mat, MAT_W, MAT_K);

    //zadanie 2.
    cout << "Zadanie 2." << endl;
    Arr <int>arrObj{ 6 };
    arrObj.fill();
    arrObj.print();

    //zadanie 3.
    cout << "Zadanie 3." << endl;
    Vec <char>vecObj{};
    //dodaj wystarczajaco duzo elementow aby wektor musial sie wydluzyc
    vecObj.push('a');
    for(char i=0; i<25; i++)
        vecObj.push( (i + 60) );
    vecObj.print();
    vecObj.pop();
    vecObj.print();

    //wskaznik do tablicy z danymi
    char * newVec = vecObj.getPointer();
    cout << newVec[0] << newVec[1] << newVec[2] << endl;

    return 0;
}
