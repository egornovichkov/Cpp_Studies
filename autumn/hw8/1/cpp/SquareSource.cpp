#include "../hpp/Rectangle.hpp"
#include "../hpp/Square.hpp"
#include <iostream>

std::ostream& Square::print() const 
{
    std::streambuf * buf = std::cout.rdbuf();
    std::ostream out(buf);
    out << "Side: " << m_length;
    return out;
}