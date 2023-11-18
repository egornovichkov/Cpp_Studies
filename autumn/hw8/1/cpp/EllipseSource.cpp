#include "../hpp/Ellipse.hpp"
#include <iostream>

double Ellipse::perimetr()
{
    return 4 * (my_pi * m_axis1 * m_axis2 + (m_axis1 - m_axis2) * (m_axis1 - m_axis2)) / (m_axis1 + m_axis2);
}

double Ellipse::square()
{
    return my_pi * m_axis1 * m_axis2;
}

std::string Ellipse::print() const
{
    std::string axis1 = std::to_string(m_axis1);
    std::string axis2 = std::to_string(m_axis2);
    std::string out = "First half-axis: " + axis1 + "\n" + "Second half-axis: " + axis2 + "\n";
    return out;
}
