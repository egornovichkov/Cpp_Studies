#include <stdexcept>
#include <string>
#pragma once

class agregate_out_of_range : public std::exception
{
public:
    agregate_out_of_range(){}
    virtual const char* what() const noexcept
{
    return "Array index is out of range";
}
};