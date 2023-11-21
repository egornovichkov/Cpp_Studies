#pragma once
#include <stdexcept>

class out_of_range : public std::exception
{
public:
    out_of_range(){}
    virtual const char* what() const noexcept
{
    return "Array index is out of range";
}
};