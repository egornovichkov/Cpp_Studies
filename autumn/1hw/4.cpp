#include <iostream>

int main()
{
    float x = 5050;
    float y = -237237;
    x = (x + y) / 2;
    y = x - y;
    x = x - y;
    y = 2*y + x;
    std::cout << "x = " << x << ", y = " << y;
}