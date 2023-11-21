#pragma once
#include <stdexcept>

class logic_error : public std::exception
{
public:
    explicit logic_error(const char* msg) : m_msg(msg){}
    virtual const char* what() const noexcept
{
    if (m_msg != nullptr)
        return m_msg;
    return "Logic error";
}
private:
    const char* m_msg;
};