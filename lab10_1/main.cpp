#include <iostream>
#include <fstream>
#include "include/csvLib.h"

int main() {

    using namespace std;

    csvLib reader("../data.csv", ',');
    reader.read();
    reader.write("../output.csv");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
