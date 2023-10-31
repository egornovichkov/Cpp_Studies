#include "../hpp/Triangle.hpp"
#include <iostream>
#include <cmath>

bool Triangle::validate_triangle(double side1, double side2, double side3)
{
    validate(side1);
    validate(side2);
    validate(side3);
    if (side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2)
    {
        std::cout << "It is not a triangle";
        exit;
    }
    return 1;
}

Triangle::Triangle(double side1, double side2, double side3) : m_side1(0), m_side2(0), m_side3(0)
{
    if (validate_triangle(side1, side2, side3) == 1)
    {
        m_side1 = side1;
        m_side2 = side2;
        m_side3 = side3;
    }
}

double Triangle::perimetr()
{
    return m_side1 + m_side2 + m_side3;
}

double Triangle::square()
{
    return std::sqrt((m_side1 + m_side2 + m_side3) * (m_side1 + m_side2 - m_side3) *
                     (m_side1 + m_side3 - m_side2) * (m_side2 + m_side3 - m_side1)) / 4;
}

std::string Triangle::print() const
{
    std::string side1 = std::to_string(m_side1);
    std::string side2 = std::to_string(m_side2);
    std::string side3 = std::to_string(m_side3);
    std::string out = "First side: " + side1 + "\n" + "Second side: " + side2 + "\n" + "Third side: " + side3 + "\n";
    return out;
}