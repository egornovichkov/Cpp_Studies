#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.hpp"

class Polygon : public Shape
{
public:
    virtual double perimetr() = 0;
    virtual double square() = 0;
    virtual ~Polygon(){};
protected:
    virtual std::string print() const = 0;
};
#endif