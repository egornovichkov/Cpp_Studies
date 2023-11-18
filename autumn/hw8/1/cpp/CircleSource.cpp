#include "../hpp/Circle.hpp"

double Circle::perimetr()
{
    return 2*my_pi*m_axis1;
}

std::string Circle::print() const
{
    std::string axis1 = std::to_string(m_axis1);
    std::string out = "Radius: " + axis1 +"\n";
    return out;
}