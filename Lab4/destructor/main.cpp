#include <iostream>
#include "Typ.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Typ *typ = new Typ[1024];

    int test;
    std::cin >> test;

    delete typ;

    return 0;
}
