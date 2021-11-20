//
// Created by Franek on 18.10.2021.
//

#include <iostream>
#include <math.h>

class Vector {
private:
    double x=0, y=0;

public:
    Vector() {};

    Vector(double x, double y) : x(x), y(y) {}

    double length() {
        return sqrt(x * x + y * y);
    }

    Vector operator+(const Vector &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Vector &operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }

    Vector operator-(const Vector &rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    Vector &operator-=(const Vector &rhs) {
        this->x = this->x - rhs.x;
        this->y = this->y - rhs.y;
        return *this;
    }

    double operator*(const Vector &rhs) const {
        return x * rhs.x + y * rhs.y;
    }

    Vector operator*(const double &rhs) const {
        return {x * rhs, y * rhs};
    }

    Vector &operator*=(const double &rhs) {
        this->x = this->x * rhs;
        this->y = this->y * rhs;
        return *this;
    }

    Vector &operator-() {
        this->x *= -1;
        this->y *= -1;
        return *this;
    }

    bool operator==(const Vector &rhs) const {
        if(x == rhs.x && y == rhs.y)
            return true;
        return false;
    }

    friend std::ostream& operator<<(std::ostream & lhs, Vector &v){
        lhs << "x: " << v.x << ", y: " << v.y;
        return lhs;
    }


    void print(){
        std::cout << "x: " << this->x << ", y: " << this->y << std::endl;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    Vector v1, v2(5,5);
    v1+=(v2);
    if(v1 == v2)
        std::cout << "Wektory sa identyczne!" << std::endl;
    std::cout << v1 << std::endl << v2 << std::endl;


    return 0;
}
