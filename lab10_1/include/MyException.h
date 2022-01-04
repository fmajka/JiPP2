//
// Created by Franek on 04.01.2022.
//

#ifndef LAB10_1_MYEXCEPTION_H
#define LAB10_1_MYEXCEPTION_H


#include <exception>

class MyException: public std::exception {
private:
    char *exceptionText;

public:
    MyException(char * exceptionText);

    const char * what();
};


#endif //LAB10_1_MYEXCEPTION_H
