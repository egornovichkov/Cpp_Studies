#include <iostream>
#include "Fraction.hpp"
int main()
{
    Fraction frac1(1, 4);
    Fraction frac2(-1, 7);
    std::cout << frac1;
    std::cout << frac2;
    Fraction frac3 = frac1 + frac2;
    std::cout << frac3;
    Fraction frac4(1, 5);
    auto frac5 = frac4++;
    std::cout << frac5;
    auto frac6 = ++frac4;
    std::cout << frac6;
    auto frac7 = frac1 * frac2;
    std::cout << frac7;
    std::cout << frac4.get_denominator();
    Fraction frac8;
    std::cin >> frac8;
    std::cout << frac8;
}
