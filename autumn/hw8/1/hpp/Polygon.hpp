#include <iostream>

class Polygon : public Shape
{
public:
    virtual double perimetr() = 0;
    virtual double square() = 0;
    virtual ~Polygon();
protected:
    virtual std::ostream& print() const = 0;
};
