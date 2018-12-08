#include "circular.h"


double Circular::area() const {
    return PI * radius * radius;
}

void Circular::set_radius(double r) {
    radius = r;
}

double Circular::get_perimeter() {
    return 2 * PI * radius;
}

double Circular::get_radius() {
    return radius;
}
