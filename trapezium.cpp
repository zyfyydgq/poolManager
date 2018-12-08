#include "Trapezium.h"
#include <cmath>
#include <iostream>

using namespace std;

Trapezium::Trapezium() {
    upLength = 0;
    downLength = 0;
    height = 0;
}

Trapezium::Trapezium(double downLength) {
    this->upLength = downLength / 3;
    this->downLength = downLength;
    this->height = downLength / 3;
}

double Trapezium::area() const {
    return (upLength + downLength) * height / 2;
}

double Trapezium::get_perimeter() {
    double  h;
    h = sqrt((upLength - downLength / 2) * (upLength - downLength / 2) + height * height);
    return h * 2 + upLength + downLength;
}

double Trapezium::get_downLength() {
    return this->downLength;
}

double Trapezium::get_upLength() {
    return this->upLength;
}

double Trapezium::get_height() {
    return this->height;
}

void Trapezium::set_attribute(double downLength) {
    this->upLength = downLength / 3;
    this->downLength = downLength;
    this->height = downLength / 3;

}
