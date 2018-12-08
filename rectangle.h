#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "base.h"


class Rectangle : public Shape {
public:
    virtual double area() const;
    void set_attribute(double l, double w);
    double get_perimeter();
    double get_length();
    double get_width();
protected:
    double length;
    double width;
};


#endif // RECTANGLE_H
