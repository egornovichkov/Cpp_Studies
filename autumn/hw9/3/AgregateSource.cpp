#include <iostream>
#include <string>
#include "Agregate.hpp"
#include "Exceptions/agregate_logic_error.hpp"
#include "Exceptions/agregate_out_of_range.hpp"
#include "Exceptions/agregate_size_limit.hpp"

Agregate::Agregate() : m_size1(10), m_size2(10), m_ptr1(nullptr), m_ptr2(nullptr), m_string("Default")
{
    std::cout << "Agregate()\n";

    try
    {
        m_ptr1 = new int[m_size1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        m_ptr2 = new int[m_size2];

        for (size_t i = 0; i < m_size1; i++)
        {
            m_ptr1[i] = 0;
        }

        for (size_t i = 0; i < m_size2; i++)
        {
            m_ptr2[i] = 0;
        }
    }
    catch(const std::exception& e)
    {
        if (m_ptr1 != nullptr)
            delete[] m_ptr1;
        std::cerr << e.what() << '\n';
    }
    
}

Agregate::Agregate(int size1, int size2, int *arr1, int *arr2, const std::string &str)
try : m_size1(validate_size(size1)), m_size2(validate_size(size2)), m_ptr1(arr1), m_ptr2(arr2), m_string("")
{
    m_ptr1 = new int[m_size1];
    m_ptr2 = new int[m_size2];
}
catch (const std::exception &e)
{
    if (m_ptr1 != nullptr)
        delete[] m_ptr1;
    std::cerr << e.what() << '\n';
}

Agregate::Agregate(const Agregate &other) : m_size1(0), m_size2(0), m_ptr1(nullptr), m_ptr2(nullptr), m_string("")
{

    std::cout << "Agregate(const Agregate&)\n";

    try
    {
        if (&other == this)
        {
            return;
        }

        if (!other.is_empty1())
        {
            m_size1 = other.m_size1;
            m_ptr1 = new int[validate_size(m_size1)];
            for (size_t i = 0; i < m_size1; i++)
            {
                m_ptr1[i] = other.m_ptr1[i];
            }
        }

        if (!other.is_empty2())
        {
            m_size2 = other.m_size2;
            m_ptr2 = new int[validate_size(m_size2)];
            for (size_t i = 0; i < m_size2; i++)
            {
                m_ptr2[i] = other.m_ptr2[i];
            }
        }

        m_string = other.m_string;
    }
    catch (const std::exception &e)
    {
        if (m_ptr1 != nullptr)
            delete[] m_ptr1;
        std::cerr << e.what() << '\n';
    }
}

Agregate::Agregate(Agregate &&other) noexcept : m_size1(0), m_size2(0), m_ptr1(nullptr), m_ptr2(nullptr), m_string("")
{
    std::cout << "Agregate(Agregate&&)\n";

    if (&other == this)
    {
        return;
    }

    if (!other.is_empty1())
    {
        m_size1 = other.m_size1;
        m_ptr1 = other.m_ptr1;
        other.m_ptr1 = nullptr;
        other.m_size1 = 0;
    }

    if (!other.is_empty2())
    {
        m_size2 = other.m_size2;
        m_ptr2 = other.m_ptr2;
        other.m_ptr2 = nullptr;
        other.m_size2 = 0;
    }

    m_string = std::move(other.m_string);
}

Agregate &Agregate::operator=(const Agregate &other)
{
    std::cout << "operator=(const Agregate&)\n";

    try
    {
        if (&other == this)
        {
            return *this;
        }

        if (!this->is_empty1())
        {
            delete[] m_ptr1;
            m_ptr1 = nullptr;
            m_size1 = 0;
        }

        if (!this->is_empty2())
        {
            delete[] m_ptr2;
            m_ptr2 = nullptr;
            m_size2 = 0;
        }

        if (!other.is_empty1())
        {
            m_size1 = other.m_size1;
            m_ptr1 = new int[other.m_size1];
            for (size_t i = 0; i < other.m_size1; i++)
            {
                m_ptr1[i] = other.m_ptr1[i];
            }
        }

        if (!other.is_empty2())
        {
            m_size2 = other.m_size2;
            m_ptr2 = new int[other.m_size2];
            for (size_t i = 0; i < other.m_size2; i++)
            {
                m_ptr2[i] = other.m_ptr2[i];
            }
        }

        m_string = other.m_string;
        return *this;
    }
    catch (const std::exception &e)
    {
        if (m_ptr1 != nullptr)
            delete[] m_ptr1;
        std::cerr << e.what() << '\n';
    }
}

Agregate &Agregate::operator=(Agregate &&other)
{
    std::cout << "operator=(Agregate&&)\n";

    if (&other == this)
    {
        return *this;
    }

    if (!this->is_empty1())
    {
        delete[] m_ptr1;
        m_ptr1 = nullptr;
        m_size1 = 0;
    }

    if (!this->is_empty2())
    {
        delete[] m_ptr2;
        m_ptr2 = nullptr;
        m_size2 = 0;
    }

    if (!other.is_empty1())
    {
        m_ptr1 = other.m_ptr1;
        m_size1 = other.m_size1;
        other.m_ptr1 = nullptr;
        other.m_size1 = 0;
    }

    if (!other.is_empty2())
    {
        m_ptr2 = other.m_ptr2;
        m_size2 = other.m_size2;
        other.m_ptr2 = nullptr;
        other.m_size2 = 0;
    }

    m_string = std::move(other.m_string);
    return *this;
}

Agregate::~Agregate() noexcept
{
    std::cout << "~Agregate()\n";

    if (!this->is_empty1())
    {
        delete[] m_ptr1;
    }

    if (!this->is_empty2())
    {
        delete[] m_ptr2;
    }
}

int &Agregate::operator[](int index)
{
    validate_index(index, m_size1 + m_size2);
    if (index < m_size1)
    {
        return m_ptr1[index];
    }
    return m_ptr2[index - m_size1];
}

const int &Agregate::operator[](int index) const
{
    validate_index(index, m_size1 + m_size2);
    if (index < m_size1)
    {
        return m_ptr1[index];
    }
    return m_ptr2[index - m_size1];
}

bool Agregate::is_empty1() const noexcept
{
    if (m_size1 == 0)
        return true;
    return false;
}

bool Agregate::is_empty2() const noexcept
{
    if (m_size2 == 0)
        return true;
    return false;
}

void Agregate::set_string(const std::string &str)
{
    m_string = str;
}

size_t Agregate::validate_size(int size)
{
    if (size < 0)
        throw agregate_logic_error("Array size must be non-negative");
    else if (size > 100)
        throw agregate_size_limit(size);
    return size;
}

size_t Agregate::validate_index(int index, size_t end)
{
    if (index < 0)
        throw agregate_logic_error("Array index must be non-negative");
    else if (index >= end)
        throw agregate_out_of_range(index, end);
    return index;
}

std::ostream &operator<<(std::ostream &out, const Agregate &rhs)
{
    out << "Array1: ";
    if (rhs.m_size1 == 0)
    {
        out << "empty";
    }
    else
    {
        for (size_t i = 0; i < rhs.m_size1; i++)
        {
            out << rhs.m_ptr1[i] << " ";
        }
    }
    out << "\n"
        << "Array2: ";
    if (rhs.m_size2 == 0)
    {
        out << "empty";
    }
    else
    {
        for (size_t i = 0; i < rhs.m_size2; i++)
        {
            out << rhs.m_ptr2[i] << " ";
        }
    }
    out << "\n"
        << "String: ";
    if (rhs.m_string.empty())
    {
        out << "empty";
    }
    else
    {
        out << rhs.m_string;
    }
    out << "\n";
    return out;
}
