#include "../hpp/Shape.hpp"
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
                     (m_side1 + m_side3 - m_side2) * (m_side2 + m_side3 - m_side1));
}

std::ostream& Triangle::print() const
{
    std::streambuf * buf = std::cout.rdbuf();
    std::ostream out(buf);
    out << "First side: " << m_side1;
    out << "Second side: " << m_side2;
    out << "Third side: " << m_side3;
    return out;
}