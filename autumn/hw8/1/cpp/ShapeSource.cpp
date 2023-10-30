#include "../hpp/Abstract_Base.hpp"
#include "../hpp/Shape.hpp"
#include <iostream>

double Shape::validate(double val)
{
    if (val >= 0)
        return val;
    std::cout << "Length must be non-negative";
    exit;
}

std::ostream& operator<<(std::ostream &out, Shape &rhs)
{
    return rhs.print();
}