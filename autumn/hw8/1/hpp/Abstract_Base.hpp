#include <iostream>

class Abstract_Base
{
public:
    virtual double perimetr() = 0;
    virtual double square() = 0;
    virtual ~Abstract_Base();
protected:
    virtual std::ostream& print() const = 0;
    virtual double validate(double) = 0;
};