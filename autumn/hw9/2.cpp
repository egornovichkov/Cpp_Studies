#include <iostream>
#include <vector>

struct S
{
    virtual void f();
}; 

int main()
{
    S* p = nullptr;
    try
    {
        std::cout << typeid(*p).name() << '\n';
    }
    catch (const std::bad_typeid& e)
    {
        std::cout << e.what() << '\n';
        std::cout << "Exception type: " << typeid(e).name() << '\n';

    }

    std::vector v{1, 2};
    try
    {
        v.at(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Exception type: " << typeid(e).name() << '\n';
    }
    try
    {
        v.resize(-1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Exception type: " << typeid(e).name() << '\n';
    }
    try
    {
        v.resize(10000000000);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Exception type: " << typeid(e).name() << '\n';

    }
}
