#include <stdexcept>

class agregate_logic_error : public std::logic_error
{
public:
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN noexcept;
};

const char* agregate_logic_error::what() const
{
    return "Logic error";
}

class agregate_out_of_range : public std::logic_error
{
public:
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN noexcept;
};

const char* agregate_out_of_range::what() const
{
    return "Out of range";
}

#include <stdexcept>

class agregate_size_limit : public std::logic_error
{
public:
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN noexcept;
};

const char* agregate_size_limit::what() const
{
    return "Size limit";
}
