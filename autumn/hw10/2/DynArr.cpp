#include "DynArr.hpp"

template <typename T>
DynArr<T>::DynArr()
{
    m_arr = nullptr;
    m_size = 0;
}

template <typename T>
DynArr<T>::DynArr(T *arr, size_t size) : m_arr(arr), m_size(validate_size(size)){};

template <typename T>
DynArr<T>::DynArr(const DynArr &other)
{
    if (&other == this)
    {
        return;
    }

    if (!other.is_empty())
    {
        m_size = other.m_size;
        m_arr = new T[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_arr[i] = other.m_arr[i];
        }
    }

    m_arr_backup = new T[m_size];
    for (size_t i = 0; i < m_size; i++)
    {
        m_arr_backup[i] = m_arr[i]
    }
}

template <typename T>
DynArr<T>::DynArr(DynArr &&other)
{
    if (&other == this)
    {
        return;
    }

    if (!other.is_empty1())
    {
        m_size = other.m_size;
        m_arr = other.m_arr;
        other.m_ptr1 = nullptr;
        other.m_size1 = 0;
    }

    m_arr_backup = m_arr;
}

template <typename T>
DynArr<T> &DynArr<T>::operator=(const DynArr &other)
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
        delete[] m_arr_backup;
        m_arr_backup = nullptr;
    }

    if (!other.is_empty())
    {
        m_size = other.m_size;
        m_arr = new T[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_arr[i] = other.m_arr[i];
        }
        m_arr_backup = new T[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_arr_backup[i] = m_arr[i];
        }
    }

    return *this;
}
template <typename T>
DynArr<T> &DynArr<T>::operator=(DynArr &&other)
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
        delete[] m_arr_backup;
        m_arr_backup = nullptr;
    }

    if (!other.is_empty1())
    {
        m_arr = other.m_arr;
        m_size = other.m_size;
        other.m_arr = nullptr;
        other.m_size = 0;
        m_arr_backup = new T[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_arr_backup[i] = m_arr[i];
        }
    }
}

template <typename T>
DynArr<T>::~DynArr() noexcept
{
    delete[](m_arr);
    delete[](m_arr_backup);
    m_size = 0;
}

template <typename T>
T &DynArr<T>::operator[](size_t index)
{
    try
    {
        validate_index(index, m_size);
        return m_arr[index];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
const T &DynArr<T>::operator[](size_t index) const
{
    try
    {
        validate_index(index, m_size);
        return m_arr[index];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
void DynArr<T>::resize(int size)
{
    try
    {
        validate_size(size);
        if (size > m_size)
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}

// void push_back(T);

// size_t validate_index(int);

// size_t validate_size(int);

// void swap(const &DynArr, const &DynArr) noexcept;

// size_t size(const &DynArr) const noexcept;
