#ifndef ABSTRACT_BASE_H
#define ABSTRACT_BASE_H
#include <iostream>
#include <string>

class Abstract_Base
{
public:
    virtual double perimetr() = 0;
    virtual double square() = 0;
    virtual ~Abstract_Base(){};
protected:
    virtual std::string print() const = 0;
    virtual double validate(double) = 0;
};
#endif