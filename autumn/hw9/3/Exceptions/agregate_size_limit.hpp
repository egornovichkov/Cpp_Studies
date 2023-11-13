#include <stdexcept>
#include <string>
#pragma once

class agregate_size_limit : public std::exception
{
public:
    agregate_size_limit(){}
    virtual const char* what() const noexcept
{
    return "Array size limit is 100";
}
};