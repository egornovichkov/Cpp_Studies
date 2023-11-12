#include <iostream>
#include <numeric>
#pragma once

enum class sign
{
    minus = 0,
    plus = 1
};

class Fraction
{
public:
    friend Fraction operator+(const Fraction &, const Fraction &);
    friend Fraction operator-(const Fraction &, const Fraction &);
    friend Fraction operator*(const Fraction &, const Fraction &);
    friend Fraction operator/(const Fraction &, const Fraction &);

    friend std::ostream &operator<<(std::ostream &, const Fraction &);
    friend std::istream &operator>>(std::istream &, Fraction &);

    // Написанные конструкторы позволяют свободно пользоваться отрицательными числами в инициализации объектов класса благодаря валидаторам, которые
    // меняют знак дроби (m_sign) если видят в числителе или знаменателе отриц. число. Именно благодаря валидаторам я не пользовался explicit конструкторами.
    Fraction(int nominator, int denominator)
        : m_sign(sign::plus), m_nominator(validate_nominator(nominator)), m_denominator(validate_denominator(denominator)) 
    {
        this->fraction_reduction();
    }

    // UPD: Конструктор с 3 аргументами я скрыл от пользователя, перенеся в private, т.к. он действительно вносил путанницу. Теперь знак дроби можно задать,
    // передавая в конструктор отрицтательные числитель и/или знаменатель.

    Fraction()
        : m_sign(sign::plus), m_nominator(0), m_denominator(1) {}

    operator double() const;

    bool operator==(const Fraction &);
    bool operator>(const Fraction &);
    bool operator<(const Fraction &);
    bool operator>=(const Fraction &);
    bool operator<=(const Fraction &);

    Fraction &operator++();
    Fraction &operator--();
    Fraction operator++(int);
    Fraction operator--(int);

    const unsigned int &get_nominator() const;
    const unsigned int &get_denominator() const;
    const sign &get_sign() const;

private:
    void fraction_reduction();

    // Метод возвращает инвертированный знак дроби
    sign get_inverted_sign() const;

    // Метод возвращает числитель с учетом знака дроби
    int get_signed_nominator() const;

    unsigned int validate_nominator(int);

    unsigned int validate_denominator(int);

    mutable sign m_sign;
    mutable unsigned int m_nominator;
    mutable unsigned int m_denominator;
};
