#include "rectangle.h"



double Rectangle::area() const{
    return this->length * this->width;
};

void Rectangle::set_attribute(double l, double w) {
    length = l;
    width = w;
}

double Rectangle::get_perimeter() {
    return 2 * (length + width);
}

double Rectangle::get_length(){
    return length;
}
double Rectangle::get_width() {
    return width;
}
