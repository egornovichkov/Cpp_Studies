#include <iostream>
#pragma once

template <typename T>
class DynArr
{
public:
    DynArr();

    DynArr(T *arr, size_t size) : m_arr(arr), m_arr_backup(arr), m_size(size);

    DynArr(const DynArr &);

    DynArr(DynArr &&);

    DynArr &operator=(const DynArr &);

    DynArr &operator=(DynArr &&);

    ~DynArr() noexcept;

    T &operator[](size_t);

    const T &operator[](size_t) const;

    void resize(int size);

    void push_back(T);

    bool is_empty();

    size_t size(const DynArr &) const noexcept;

    void swap(const DynArr &, const DynArr&) noexcept;

private:

    size_t static validate_index(int, size_t);

    T *m_arr;
    T *m_arr_backup;
    size_t m_size;
};
