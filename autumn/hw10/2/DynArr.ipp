#pragma once
#include <iostream>
#include <algorithm>
#include "Exceptions/logic_error.hpp"
#include "Exceptions/out_of_range.hpp"

template <typename T>
DynArr<T>::DynArr() noexcept : m_arr(nullptr), m_arr_backup(nullptr), m_size(0)
{
    std::cout << "DynArr()\n";
}

template <typename T>
DynArr<T>::DynArr(T *arr, size_t size) : m_arr(nullptr), m_arr_backup(nullptr), m_size(0)
{
    std::cout << "DynArr(T *, size_t)\n";

    try
    {
        m_arr = new T[size];
        m_size = size;
        for (size_t i = 0; i < m_size; i++)
        {
            m_arr[i] = arr[i];
        }
        this->backup();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
};

template <typename T>
DynArr<T>::DynArr(const DynArr &other) : m_arr(nullptr), m_arr_backup(nullptr), m_size(0)
{
    std::cout << "DynArr(const DynArr &)\n";

    try
    {
        if (&other == this || other.is_empty())
        {
            return;
        }

        if (!other.is_empty())
        {
            m_arr = new T[other.m_size];
            m_size = other.m_size;
            for (size_t i = 0; i < m_size; i++)
            {
                m_arr[i] = other.m_arr[i];
            }
        }

        this->backup();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
DynArr<T>::DynArr(DynArr &&other) noexcept : m_arr(nullptr), m_arr_backup(nullptr), m_size(0)
{
    std::cout << "DynArr(DynArr &&)\n";

    if (&other == this || other.is_empty())
    {
        return;
    }

    if (!other.is_empty())
    {
        m_size = other.m_size;
        m_arr = other.m_arr;
        m_arr_backup = other.m_arr_backup;
        other.m_arr = nullptr;
        other.m_arr_backup = nullptr;
        other.m_size = 0;
    }
}

template <typename T>
DynArr<T> &DynArr<T>::operator=(const DynArr &other)
{
    std::cout << "operator=(const DynArr&)\n";

    try
    {
        if (&other == this)
        {
            return *this;
        }

        if (!this->is_empty())
        {
            delete[] m_arr;
            m_arr = nullptr;
            m_size = 0;
        }

        if (!other.is_empty())
        {
            m_arr = new T[other.m_size];
            m_size = other.m_size;
            for (size_t i = 0; i < m_size; i++)
            {
                m_arr[i] = other.m_arr[i];
            }
        }

        this->backup();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return *this;
}
template <typename T>
DynArr<T> &DynArr<T>::operator=(DynArr &&other) noexcept
{
    std::cout << "operator=(DynArr &&)\n";

    if (&other == this)
    {
        return *this;
    }

    if (!this->is_empty())
    {
        delete[] m_arr;
        m_arr = nullptr;
        m_size = 0;
    }

    if (!other.is_empty())
    {
        m_arr = other.m_arr;
        m_size = other.m_size;
        other.m_arr = nullptr;
        other.m_size = 0;
    }

    this->backup();

    return *this;
}

template <typename T>
DynArr<T>::~DynArr() noexcept
{
    std::cout << "~DynArr()\n";

    if (this->is_empty())
        return;
    delete[] m_arr;
    delete[] m_arr_backup;
    m_size = 0;
}

template <typename T>
T &DynArr<T>::operator[](size_t index)
{
    return m_arr[validate_index(index, m_size)];
}

template <typename T>
const T &DynArr<T>::operator[](size_t index) const
{
    return m_arr[validate_index(index, m_size)];
}

template <typename T>
void DynArr<T>::resize(size_t size)
{
    try
    {
        if (this->is_empty())
        {
            m_arr = new T[size];
            m_arr_backup = new T[size];
            m_size = size;
            return;
        }
        m_arr_backup = m_arr;
        m_arr = nullptr;
        m_arr = new T[size];
        for (size_t i = 0; i < std::min(m_size, size); i++)
        {
            m_arr[i] = m_arr_backup[i];
        }
        m_size = size;
        this->backup();
    }
    catch (const std::exception &e)
    {
        this->recovery_from_backup();
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
void DynArr<T>::push_back(const T &elem)
{
    try
    {
        m_arr_backup = m_arr;
        m_arr = new T[m_size + 1];
        ++m_size;
        for (size_t i = 0; i < m_size - 1; i++)
        {
            m_arr[i] = m_arr_backup[i];
        }
        m_arr[m_size - 1] = elem;
        this->backup();
    }
    catch (const std::exception &e)
    {
        this->recovery_from_backup();
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
void DynArr<T>::pop_back()
{
    try
    {
        m_arr_backup = m_arr;
        m_arr = new T[m_size - 1];
        --m_size;
        for (size_t i = 0; i < m_size; i++)
        {
            m_arr[i] = m_arr_backup[i];
        }
        this->backup();
    }
    catch (const std::exception &e)
    {
        this->recovery_from_backup();
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
void DynArr<T>::clear() noexcept
{
    if (this->is_empty())
        return;
    delete[] m_arr;
    delete[] m_arr_backup;
    m_arr = nullptr;
    m_arr_backup = nullptr;
    m_size = 0;
}

template <typename T>
bool DynArr<T>::is_empty() const noexcept
{
    if (m_size == 0)
        return true;
    return false;
}

template <typename T>
size_t DynArr<T>::size() const noexcept
{
    return m_size;
}

template <typename T>
size_t DynArr<T>::validate_index(int index, size_t end)
{
    if (index < 0)
    {
        throw logic_error("Array index must be non-negative");
    }
    if (index >= end)
    {
        throw out_of_range();
    }
    return index;
}

template <typename T>
void DynArr<T>::swap(DynArr &rhs) noexcept
{
    DynArr temp = std::move(*this);
    *this = std::move(rhs);
    rhs = std::move(temp);
}

template <typename T>
void DynArr<T>::backup() noexcept
{
    try
    {
        if (m_arr_backup)
            delete[] m_arr_backup;
        m_arr_backup = new T[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_arr_backup[i] = m_arr[i];
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Backup failed\n";
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
void DynArr<T>::recovery_from_backup() noexcept
{
    try
    {
        if (this->is_empty())
            return;
        if (m_arr)
            delete[] m_arr;
        m_arr = new T[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_arr[i] = m_arr_backup[i];
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Recovery from backup failed\n";
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const DynArr<T> &rhs)
{
    for (size_t i = 0; i < rhs.m_size; i++)
    {
        out << rhs.m_arr[i] << " ";
    }
    return out;
}

template <typename T>
std::istream &operator>>(std::istream &in, DynArr<T> &rhs)
{
    for (size_t i = 0; i < rhs.m_size; i++)
    {
        in >> rhs.m_arr[i];
    }
    rhs.backup();
    return in;
}