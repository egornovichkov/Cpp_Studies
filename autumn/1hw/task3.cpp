#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "");
    double a;
    double b;
    double c;
    std::cout << "a=";
    std::cin >> a;
    std::cout << "b=";
    std::cin >> b;
    std::cout << "c=";
    std::cin >> c;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                std::wcout << L"Решением является любое число";
            }
            else
            {
                std::wcout << L"Решений нет";
            }
        }
        else
        {
            std::wcout << L"Единственное решение: " << -c / b;
        }
    }
    else
    {
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0)
        {
            std::wcout << L"Решения: " << (-b - sqrt(discriminant)) / (2 * a) << ", " << (-b + sqrt(discriminant)) / (2 * a);
        }
        if (discriminant == 0)
        {
            std::wcout << L"Единственное решение: " << -b / (2 * a);
        }
        if (discriminant < 0)
        {
            std::wcout << L"Решений нет";
        }
    }
}