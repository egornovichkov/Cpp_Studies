#include <iostream>
#include <numeric>
enum class sign
{
    minus = 0,
    plus = 1
};

class Fraction
{
public:
    friend Fraction operator+(Fraction &, Fraction &);
    friend Fraction operator-(Fraction &, Fraction &);
    friend Fraction operator*(Fraction &, Fraction &);
    friend Fraction operator/(Fraction &, Fraction &);
    friend std::ostream &operator<<(std::ostream &, Fraction &);

    // Написанные конструкторы позволяют свободно пользоваться отрицательными числами в инициализации объектов класса благодаря валидаторам, которые
    // меняют знак дроби (m_sign) если видят в числителе или знаменателе отриц. число. Именно благодаря валидаторам я не пользовался explicit конструкторами.
    Fraction(int nominator, int denominator)
        : m_sign(sign::plus), m_nominator(validate_nominator(nominator)), m_denominator(validate_denominator(denominator)) {}

    // Этот конструктор позволяет явно указать знак перед дробью и также валидирует значения корректным образом. На самом деле бесполезен.
    Fraction(sign sign, int nominator, int denominator)
        : m_sign(sign), m_nominator(validate_nominator(nominator)), m_denominator(validate_denominator(denominator)) {}

    bool operator==(Fraction &);
    bool operator>(Fraction &);
    bool operator<(Fraction &);
    bool operator>=(Fraction &);
    bool operator<=(Fraction &);

    Fraction &operator++();
    Fraction &operator--();
    Fraction operator++(int);
    Fraction operator--(int);

    const unsigned int &get_nominator();
    const unsigned int &get_denominator();
    const sign &get_sign();

    double decimal_fraction();

private:
    void fraction_reduction();
    sign sign_change();

    unsigned int validate_nominator(int);

    unsigned int validate_denominator(int);

    sign m_sign;
    unsigned int m_nominator;
    unsigned int m_denominator;
};
