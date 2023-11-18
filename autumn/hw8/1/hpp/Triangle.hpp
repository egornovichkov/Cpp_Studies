#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Polygon.hpp"

class Triangle final : public Polygon
{
public:
    Triangle(double, double, double);
    virtual double perimetr() final;
    virtual double square() final;

    virtual ~Triangle(){};

protected:
    virtual std::string print() const final;

    bool validate_triangle(double, double, double);

    double m_side1;
    double m_side2;
    double m_side3;
};
#endif