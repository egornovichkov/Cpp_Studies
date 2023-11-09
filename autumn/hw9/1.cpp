#include <iostream>
#include <cmath>
#include <variant>

enum class ReturnCode
{
    negative_arg = -1,
    zero_arg = -2,
    arg_equal_1 = -3,
    too_large_arg = -4
};

std::variant<ReturnCode, double> my_ln(double x)
{
    if (x == 0)
        return ReturnCode::zero_arg;
    if (x < 0)
        return ReturnCode::negative_arg;
    if (x == 1)
        return ReturnCode::arg_equal_1;
    if (x > 1e20)
        return ReturnCode::too_large_arg;
    return std::log(x);
}

void print(const std::variant<ReturnCode, double> &v)
{
    if (std::holds_alternative<ReturnCode>(v))
    {
        switch (std::get<ReturnCode>(v))
        {
        case ReturnCode::negative_arg:
            std::cout << "Arguement can not be negative\n";
            break;
        case ReturnCode::zero_arg:
            std::cout << "Arguement can not be equal to 0\n";
            break;
        case ReturnCode::arg_equal_1:
            std::cout << "Arguement can not be equal to 1\n";
            break;
        case ReturnCode::too_large_arg:
            std::cout << "Arguement can not be greater than 1e20\n";
            break;
        }
    }
    else
        std::cout << "Value: " << std::get<double>(v) << "\n";
}

int main()
{
    double x1 = -1;
    double x2 = 0;
    double x3 = 1;
    double x4 = 1e21;
    double x5 = 10;
    print((my_ln(x1)));
    print((my_ln(x2)));
    print((my_ln(x3)));
    print((my_ln(x4)));
    print((my_ln(x5)));
}