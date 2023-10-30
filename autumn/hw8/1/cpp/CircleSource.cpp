#include "../hpp/Ellipse.hpp"
#include "../hpp/Circle.hpp"
#include <iostream>

double Circle::perimetr()
{
    return 2*pi*m_axis1;
}

double Circle::square()
{
    return pi*m_axis1*m_axis1;
}

std::ostream& Circle::print() const
{
    std::streambuf * buf = std::cout.rdbuf();
    std::ostream out(buf);
    out << "Radius: " << m_axis1;
    return out;
}