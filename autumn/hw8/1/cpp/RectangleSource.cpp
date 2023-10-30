#include "../hpp/Rectangle.hpp"
#include "../hpp/Polygon.hpp"
#include <iostream>

double Rectangle::perimetr()
{
    return 2*(m_length+m_width);
}

double Rectangle::square()
{
    return m_length*m_width;
}

std::ostream& Rectangle::print() const
{
    std::streambuf * buf = std::cout.rdbuf();
    std::ostream out(buf);
    out << "Length: " << m_length;
    out << "Width: " << m_width;
    return out;
}