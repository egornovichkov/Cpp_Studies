#include "iostream"

template<typename F1, typename F2, typename... Args>
void my_map(F1 func1, F2 func2, Args... args)
{
    func1(args...);
    func2(args...);
}


void func1(int a, double b)
{
    std::cout << a << " " << b << "\n";
}

void func2(int a, double b)
{
    std::cout << a*a << " " << b*b << "\n";
}

void func3(char a, char b, char c)
{
    std::cout << a << " " << b << " " << c<< "\n";
}

void func4(char a, char b, char c)
{
    std::cout << static_cast<char>(a + 1) << " " << static_cast<char>(b + 1) << " " << static_cast<char>(c + 1) << "\n";
}

int main()
{
    my_map(func1, func2, 2, 5.5);
    my_map(func3, func4, 'a', 'b', 'c');
    my_map(func1, [](int a, double b){std::cout << -a << " " << -b << "\n";}, 10, 1.1);
}
