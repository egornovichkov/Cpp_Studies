#include "../hpp/Square.hpp"
#include <iostream>

std::string Square::print() const 
{
    std::string length = std::to_string(m_length);
    std::string out = "Side: " + length + "\n";
    return out;
}