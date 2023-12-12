#pragma once
#include <utility>

template <typename T>
StupidSmartPointer<T>::StupidSmartPointer()
{
    m_data = nullptr;
}

template <typename T>
StupidSmartPointer<T>::StupidSmartPointer(T *ptr)
{
    m_data = ptr;
}

template <typename T>
void StupidSmartPointer<T>::release()
{
    if (m_data)
        delete m_data;
    m_data = nullptr;
}

template <typename T>
void StupidSmartPointer<T>::reset(T *ptr)
{
    this->release();
    m_data = ptr;
}

template <typename T>
T *StupidSmartPointer<T>::get()
{
    return m_data;
}

template <typename T>
StupidSmartPointer<T>::operator bool()
{
    return static_cast<bool>(m_data);
}

template <typename T>
T &StupidSmartPointer<T>::operator*()
{
    if (!m_data)
    {
        throw -1;
    }
    return *m_data;
}

template <typename T>
StupidSmartPointer<T>::~StupidSmartPointer() noexcept
{
    this->release();
}

template <typename T>
template <typename... Types>
void StupidSmartPointer<T>::emplace(Types&&... params)
{
    this->release();
    m_data = new T((std::forward<Types>(params))...);
}
