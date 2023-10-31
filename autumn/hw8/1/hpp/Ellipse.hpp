#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shape.hpp"

class Ellipse : public Shape
{
public:
    Ellipse() : m_axis1(0), m_axis2(0){}
    Ellipse(double axis1, double axis2) : m_axis1(validate(axis1)), m_axis2(validate(axis2)){}

    virtual ~Ellipse(){};

    virtual double perimetr() override;
    virtual double square() override;

protected:
    virtual std::string print() const override;
    double m_axis1;
    double m_axis2;
    const double pi = 3.1415926535;
};
#endif