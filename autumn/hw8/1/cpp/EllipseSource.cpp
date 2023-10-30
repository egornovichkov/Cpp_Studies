#include "../hpp/Shape.hpp"
#include "../hpp/Ellipse.hpp"
#include <iostream>

double Ellipse::perimetr()
{
    return 4 * (pi * m_axis1 * m_axis2 + (m_axis1 - m_axis2)*(m_axis1 - m_axis2)) / (m_axis1 + m_axis2);
}

double Ellipse::square()
{
    return pi * m_axis1 * m_axis2;
}

std::ostream& Ellipse::print() const
{
    std::streambuf * buf = std::cout.rdbuf();
    std::ostream out(buf);
    out << "First half-axis: " << m_axis1;
    out << "Second half-axis: " << m_axis2;
    return out;
}

