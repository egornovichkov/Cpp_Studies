#include <iostream>
#include <vector>
#include <functional>

using function = std::function<double(double, double)>;

int main()
{
    const double pi = 3.14159265358979311600;
    function lambda1 = [](double x, double y)
    { return x + y; };
    function lambda2 = [](double x, double y)
    { return x - y; };
    function lambda3 = [](double x, double y)
    { return x * y; };
    function lambda4 = [](double x, double y)
    { return x * x + y * y; };
    function lambda5 = [&pi](double x, double y)
    { return pi * x * y; };

    std::vector<function> array_lambda{lambda1, lambda2, lambda3, lambda4, lambda5};
    double x, y;
    std::cout << "Input x: ";
    std::cin >> x;
    std::cout << "Input y: ";
    std::cin >> y;
    int i = 0;
    for (auto func : array_lambda)
    {
        ++i;
        std::cout << "Lambda" << i << "(x, y) = " << func(x, y) << "\n";
    }
    return 0;
}
