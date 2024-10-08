#pragma once
#include <iostream>
#include <string>
#include <array>



class Agregate
{
public:
    friend std::ostream &operator<<(std::ostream &, const Agregate &);

    Agregate();

    Agregate(int, int, int *, int *, const std::string &a = "Default");

    Agregate(const Agregate &);

    Agregate(Agregate &&) noexcept;

    Agregate &operator=(const Agregate &);

    Agregate &operator=(Agregate &&);

    ~Agregate() noexcept;

    int &operator[](int);

    const int &operator[](int) const;

    bool is_empty1() const noexcept;

    bool is_empty2() const noexcept;

    void set_string(const std::string &);

private:
    size_t static validate_size(int);
    size_t static validate_index(int, size_t);
    size_t m_size1;
    size_t m_size2;
    int *m_ptr1;
    int *m_ptr2;
    std::string m_string;
};