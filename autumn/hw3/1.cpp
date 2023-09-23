#include <iostream>

int fib(int n)
{
    if (n > 2)
        return fib(n - 1) + fib(n - 2);
    else
        return 1;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << fib(n) << "\n";
}