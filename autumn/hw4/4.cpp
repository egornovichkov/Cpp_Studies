#include <iostream>

enum class months : int
{
    january = 1,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
};

int days_in_month(months m)
{
    using enum months;
    switch (m)
    {
    case january:
        return 31;
        break;
    case february:
        return 28;
        break;
    case march:
        return 31;
        break;
    case april:
        return 30;
        break;
    case may:
        return 31;
        break;
    case june:
        return 30;
        break;
    case july:
        return 31;
        break;
    case august:
        return 31;
        break;
    case september:
        return 30;
        break;
    case october:
        return 31;
        break;
    case november:
        return 30;
        break;
    case december:
        return 31;
        break;
    default:
        std::cout << "Wrong input";
        return 0;
        break;
    }
}


int main()
{
    months m1 = months::july;
    std::cout << days_in_month(m1) << " ";
    months m2 = months::september;
    std::cout << days_in_month(m2);
    return 0;
}
