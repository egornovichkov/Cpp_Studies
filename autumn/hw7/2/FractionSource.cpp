#include <iostream>
#include <numeric>
#include "Fraction.hpp"

Fraction operator+(const Fraction &frac1, const Fraction &frac2)
{
    int frac1_nominator(frac1.get_signed_nominator());
    int frac2_nominator(frac2.get_signed_nominator());
    int lcm = std::lcm(frac1.m_denominator, frac2.m_denominator);
    int nominator(frac1_nominator * (lcm / frac1.m_denominator) + frac2_nominator * (lcm / frac2.m_denominator));
    int denominator(lcm);
    return Fraction(nominator, denominator);
}

Fraction operator-(const Fraction &frac1, const Fraction &frac2)
{

    Fraction minus_one(-1, 1);
    return frac1 + minus_one * frac2;
}

Fraction operator*(const Fraction &frac1, const Fraction &frac2)
{
    int frac1_nominator(frac1.get_signed_nominator());
    int frac2_nominator(frac2.get_signed_nominator());
    int nominator(frac1_nominator * frac2_nominator);
    int denominator(frac1.m_denominator * frac2.m_denominator);
    Fraction result(nominator, denominator);
    result.fraction_reduction();
    return result;
}

Fraction operator/(const Fraction &frac1, const Fraction &frac2)
{
    if (frac2.m_nominator == 0)
    {
        std::cout << "Can not divide by 0";
        exit;
    }
    std::swap(frac2.m_nominator, frac2.m_denominator);
    Fraction result = frac1 * frac2;
    std::swap(frac2.m_nominator, frac2.m_denominator);
    return result;
}

std::ostream &operator<<(std::ostream &out, const Fraction &rhs)
{
    if (rhs.m_nominator == 0)
    {
        out << 0 << "\n";
        return out;
    }
    out << rhs.get_signed_nominator() << "/" << rhs.get_denominator() << "\n";
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &rhs)
{
    int nominator;
    int denominator;
    std::cout << "\nInput nominator: ";
    in >> nominator;
    std::cout << "Input denominator: ";
    in >> denominator;
    rhs = Fraction(nominator, denominator);
    return in;
}

Fraction::operator double() const
{
    return double(this->get_signed_nominator()) / double(m_denominator);
}

bool Fraction::operator==(const Fraction &rhs)
{
    if ((*this - rhs).m_nominator == 0)
    {
        return 1;
    }
    return 0;
}

bool Fraction::operator>(const Fraction &rhs)
{
    if ((*this - rhs).m_sign == sign::minus || *this == rhs)
    {
        return 0;
    }
    return 1;
}

bool Fraction::operator<(const Fraction &rhs)
{
    if (*this > rhs || *this == rhs)
    {
        return 0;
    }
    return 1;
}

bool Fraction::operator>=(const Fraction &rhs)
{
    if (*this < rhs)
    {
        return 0;
    }
    return 1;
}

bool Fraction::operator<=(const Fraction &rhs)
{
    if (*this > rhs)
    {
        return 0;
    }
    return 1;
}

Fraction &Fraction::operator++()
{
    m_nominator += m_denominator;
    return *this;
}

Fraction &Fraction::operator--()
{
    m_nominator -= m_denominator;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(this->get_signed_nominator(), m_denominator);
    ++(*this);
    return temp;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(this->get_signed_nominator(), m_denominator);
    --(*this);
    return temp;
}

const unsigned int &Fraction::get_nominator() const
{
    return this->m_nominator;
}

const unsigned int &Fraction::get_denominator() const
{
    return this->m_denominator;
}

const sign &Fraction::get_sign() const
{
    return this->m_sign;
}

void Fraction::fraction_reduction()
{
    int nominator = m_nominator / std::gcd(this->m_denominator, this->m_nominator);
    int denominator = m_denominator / std::gcd(this->m_denominator, this->m_nominator);
    m_nominator = nominator;
    m_denominator = denominator;
}

sign Fraction::get_inverted_sign() const
{
    return static_cast<sign>((!static_cast<bool>(this->m_sign)));
}

int Fraction::get_signed_nominator() const
{
    if (m_sign == sign::minus)
    {
        return -m_nominator;
    }
    return m_nominator;
}

unsigned int Fraction::validate_nominator(int x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        m_sign = this->get_inverted_sign();
        return (-x);
    }
}

unsigned int Fraction::validate_denominator(int x)
{
    if (x > 0)
    {
        return x;
    }
    else if (x == 0)
    {
        std::cout << "Denominator can not be equal to 0";
        exit;
    }
    m_sign = this->get_inverted_sign();
    return (-x);
}
