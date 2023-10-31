#include "../hpp/Rectangle.hpp"
#include <iostream>

double Rectangle::perimetr()
{
    return 2*(m_length+m_width);
}

double Rectangle::square()
{
    return m_length*m_width;
}

std::string Rectangle::print() const
{
    std::string length = std::to_string(m_length);
    std::string width = std::to_string(m_width);
    std::string out = "Length: " + length + "\n" + "Width: " + width + "\n";
    return out;
}