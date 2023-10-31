#ifndef SHAPE_H
#define SHAPE_H
#include "Abstract_Base.hpp"


class Shape : public Abstract_Base
{

    friend std::ostream &operator<<(std::ostream &, Shape &);

public:
    virtual double perimetr() = 0;
    virtual double square() = 0;
    virtual ~Shape(){};
protected:
    virtual std::string print() const = 0;
    virtual double validate(double) final;
};
#endif