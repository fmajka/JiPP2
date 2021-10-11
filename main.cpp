#include <iostream>
using namespace std;

int main() {
    std::cout << "Witaj!" << std::endl;
    int *d;
    int size = 4;
    d = new int[size];
    for(int i=0; i<size; i++){
        d[i] = i;
        cout << "slot!" << d[i] << std::endl;
    }
    delete d;
    cout << d[1] << endl;

    return 0;
}
