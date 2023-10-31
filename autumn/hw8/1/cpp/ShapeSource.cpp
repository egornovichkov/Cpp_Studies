#include "../hpp/Shape.hpp"
#include <iostream>

double Shape::validate(double val)
{
    if (val < 0)
    {
        std::cout << "Length must be non-negative";
        exit;
    }
    return val;
}

std::ostream &operator<<(std::ostream &out, Shape &rhs)
{
    out << rhs.print();
    return out;
}