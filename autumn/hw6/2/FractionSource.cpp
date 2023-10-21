#include <iostream>
#include <numeric>
#include "Fraction.hpp"

Fraction operator+(Fraction &frac1, Fraction &frac2)
{
    frac1.fraction_reduction();
    frac2.fraction_reduction();
    int frac1_nominator;
    int frac2_nominator;
    if (frac1.m_sign == sign::minus)
        frac1_nominator = -frac1.m_nominator;
    else
        frac1_nominator = frac1.m_nominator;

    if (frac2.m_sign == sign::minus)
        frac2_nominator = -frac2.m_nominator;
    else
        frac2_nominator = frac2.m_nominator;
    int lcm = std::lcm(frac1.m_denominator, frac2.m_denominator);
    int nominator(frac1_nominator * (lcm / frac1.m_denominator) + frac2_nominator * (lcm / frac2.m_denominator));
    int denominator(lcm);

    return Fraction(nominator, denominator);
}

Fraction operator-(Fraction &frac1, Fraction &frac2)
{
    Fraction buf(frac2.sign_change(), frac2.m_nominator, frac2.m_denominator);
    return frac1 + buf;
}

Fraction operator*(Fraction &frac1, Fraction &frac2)
{
    int frac1_nominator;
    int frac2_nominator;
    if (frac1.m_sign == sign::minus)
        frac1_nominator = -frac1.m_nominator;
    else
        frac1_nominator = frac1.m_nominator;

    if (frac2.m_sign == sign::minus)
        frac2_nominator = -frac2.m_nominator;
    else
        frac2_nominator = frac2.m_nominator;

    int nominator(frac1_nominator * frac2_nominator);
    int denominator(frac1.m_denominator * frac2.m_denominator);
    Fraction result(nominator, denominator);
    result.fraction_reduction();
    return result;
}

Fraction operator/(Fraction &frac1, Fraction &frac2)
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

std::ostream &operator<<(std::ostream &out, Fraction &rhs)
{
    if (rhs.m_nominator == 0)
    {
        out << 0 << "\n";
        return out;
    }
    rhs.fraction_reduction();
    if (rhs.m_sign == sign::plus)
        out << rhs.m_nominator << "/" << rhs.m_denominator << "\n";
    else
        out << "-" << rhs.m_nominator << "/" << rhs.m_denominator << "\n";
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &rhs)
{
    bool input_sign;
    int nominator;
    int denominator;
    std::cout << "\nInput sign (0 is minus, 1 is plus): ";
    in >> input_sign;
    std::cout << "Input nominator: ";
    in >> nominator;
    std::cout << "Input denominator: ";
    in >> denominator;
    rhs = Fraction(static_cast<sign>(input_sign), nominator, denominator);
    return in;
}


bool Fraction::operator==(Fraction &rhs)
{
    if ((*this - rhs).m_nominator == 0)
    {
        return 1;
    }
    return 0;
}

bool Fraction::operator>(Fraction &rhs)
{
    if ((*this - rhs).m_sign == sign::minus || *this == rhs)
    {
        return 0;
    }
    return 1;
}

bool Fraction::operator<(Fraction &rhs)
{
    if (this->operator>(rhs) || *this == rhs)
    {
        return 0;
    }
    return 1;
}

bool Fraction::operator>=(Fraction &rhs)
{
    if ((*this - rhs).m_sign == sign::minus)
    {
        return 0;
    }
    return 1;
}

bool Fraction::operator<=(Fraction &rhs)
{
    if (this->operator<(rhs) || *this == rhs)
    {
        return 1;
    }
    return 0;
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
    Fraction temp(m_sign, m_nominator, m_denominator);
    ++(*this);
    return temp;
}

Fraction Fraction::operator--(int)
{
    Fraction temp(m_sign, m_nominator, m_denominator);
    --(*this);
    return temp;
}

const unsigned int &Fraction::get_nominator()
{
    return this->m_nominator;
}

const unsigned int &Fraction::get_denominator()
{
    return this->m_denominator;
}

const sign &Fraction::get_sign()
{
    return this->m_sign;
}

double Fraction::decimal_fraction()
{
    if (m_sign == sign::minus)
    {
        return -m_nominator / m_denominator;
    }
    return m_nominator / m_denominator;
}

void Fraction::fraction_reduction()
{
    int nominator = m_nominator / std::gcd(this->m_denominator, this->m_nominator);
    int denominator = m_denominator / std::gcd(this->m_denominator, this->m_nominator);
    m_nominator = nominator;
    m_denominator = denominator;
}

sign Fraction::sign_change()
{
    return static_cast<sign>((!static_cast<bool>(this->m_sign)));
}

unsigned int Fraction::validate_nominator(int x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        m_sign = this->sign_change();
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
    m_sign = this->sign_change();
    return (-x);
}
