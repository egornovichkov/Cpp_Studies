#pragma once
#include <stdexcept>
#include <string>
#include <charconv>

class agregate_size_limit : public std::exception
{
public:
    agregate_size_limit() {}
    agregate_size_limit(int size) : m_size(std::to_string(size)) {}
    virtual const char *what() const noexcept
    {
        if (m_size != "")
        {
            std::string temp("Array size can not be " + m_size + ", size limit is 100");
            return temp.c_str();
        }
        return "Array size limit is 100";
    }

private:
    std::string m_size;
};