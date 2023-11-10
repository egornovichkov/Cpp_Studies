#include <iostream>
#include <string>
#include "Agregate.hpp"

int main()
{
    Agregate test_obj1;
    for (size_t i = 0; i < 20; i++)
    {
        test_obj1[i] = i;
    }
    test_obj1.set_string("test_obj1");
    std::cout << "test_obj1:\n"
              << test_obj1;
    Agregate obj1(test_obj1);
    std::cout << "obj1:\n"
              << obj1;
    Agregate obj2(std::move(test_obj1));
    std::cout << "obj2:"
              << "\n"
              << obj2;
    std::cout << "test_obj1 is empty:\n"
              << test_obj1;
    Agregate test_obj2;
    for (size_t i = 0; i < 20; i++)
    {
        test_obj2[i] = i + 20;
    }
    test_obj2.set_string("test_obj2");
    Agregate obj3;
    obj3 = test_obj2;
    std::cout << "obj3:\n"
              << obj3;
    std::cout << test_obj2;
    Agregate obj4;
    obj4 = std::move(test_obj2);
    std::cout << "obj4\n"
              << obj4;
    std::cout << "test_obj2 is empty:\n"
              << test_obj2;
    return 0;
}
