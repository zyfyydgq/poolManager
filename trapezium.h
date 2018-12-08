#ifndef TRAPEZOID_Trapezium H
#define TRAPEZOID_Trapezium H
#include "base.h"


class Trapezium : public Shape {
public:
    virtual double area() const;
    void set_attribute(double downLength);
    double get_perimeter();
    double get_upLength();
    double get_downLength();
    double get_height();
    Trapezium();
    Trapezium(double downLength);

protected:
    double upLength;
    double downLength;
    double height;
};


#endif //TRAPEZOID_Trapezium H
