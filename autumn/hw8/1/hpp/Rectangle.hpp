#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Polygon.hpp"

class Rectangle : public Polygon
{
public:
    Rectangle(double length, double width) : m_length(validate(length)), m_width(validate(width)){}

    virtual double perimetr() final;
    virtual double square() final;

    virtual ~Rectangle(){};

protected:
    virtual std::string print() const override;
    double m_length;
    double m_width;
};
#endif