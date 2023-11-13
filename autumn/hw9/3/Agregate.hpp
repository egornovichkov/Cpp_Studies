#include <iostream>
#include <string>
#include <array>
#pragma once



class Agregate
{
public:
    friend std::ostream &operator<<(std::ostream &, const Agregate &);

    Agregate();

    Agregate(int, int, int *, int *, const std::string &a = "Default");

    Agregate(const Agregate &);

    Agregate(Agregate &&);

    Agregate &operator=(const Agregate &);

    Agregate &operator=(Agregate &&);

    ~Agregate() noexcept;

    int &operator[](int);

    const int &operator[](int) const;

    bool is_empty1() const noexcept;

    bool is_empty2() const noexcept;

    void set_string(const std::string &) noexcept;

    size_t validate_size(int) const;
    size_t validate_index(int, size_t) const;
private:
    size_t m_size1;
    size_t m_size2;
    int *m_ptr1;
    int *m_ptr2;
    std::string m_string;
};