#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>

class Shape
{

    friend std::ostream &operator<<(std::ostream &, Shape &);

public:
    virtual double perimetr() = 0;
    virtual double square() = 0;
    virtual ~Shape(){};
protected:
    virtual std::string print() const = 0;
    static double validate(double);
};
#endif