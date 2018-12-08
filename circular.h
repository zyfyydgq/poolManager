#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "base.h"


class Circular : public Shape {
public:
    virtual double area() const;
    void set_radius(double r);
    double get_perimeter();
    double get_radius();

protected:
    double radius;
};




#endif // CIRCULAR_H
