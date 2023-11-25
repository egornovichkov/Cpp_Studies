#pragma once
#include <stdexcept>
#include <string>

class agregate_out_of_range : public std::exception
{
public:
    agregate_out_of_range() {}
    agregate_out_of_range(int index, int size) : m_index(std::to_string(index)), m_size(std::to_string(size)){}
    virtual const char *what() const noexcept
    {
        if (m_index != "")
        {
            std::string temp("Array index can not be " + m_index);
            temp += ", array size is " + m_size;
            return temp.c_str();
        }
        return "Array index is out of range";
    }

private:
    std::string m_index;
    std::string m_size;
};