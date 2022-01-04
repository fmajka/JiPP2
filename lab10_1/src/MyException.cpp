//
// Created by Franek on 04.01.2022.
//

#include "../include/MyException.h"

MyException::MyException(char * exceptionText): exceptionText(exceptionText) {}

const char * MyException::what() {
    return exceptionText;
}