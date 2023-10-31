#ifndef CIRCLE_H
#define CIRCLE_H
#include "Ellipse.hpp"

class Circle final: public Ellipse
{
public:
    Circle() : Ellipse(0, 0){};
    Circle(double radius) : Ellipse(radius, radius){};

    virtual ~Circle(){};

    virtual double perimetr() final;
    virtual double square() final;
protected:
    virtual std::string print() const final;
};
#endif