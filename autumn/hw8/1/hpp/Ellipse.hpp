#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shape.hpp"

class Ellipse : public Shape
{
public:
    Ellipse(double axis1, double axis2) : m_axis1(validate(axis1)), m_axis2(validate(axis2)){}

    virtual ~Ellipse(){};

    virtual double perimetr() override;
    virtual double square() final;

protected:
    virtual std::string print() const override;
    double m_axis1;
    double m_axis2;
    static constexpr double my_pi = 3.1415926535;
};
#endif