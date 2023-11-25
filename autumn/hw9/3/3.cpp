#include <exception>
#include <iostream>
#include "Agregate.hpp"

int main()
{
    try
    {
        int *arr1{new int[4]{1, 2, 3, 4}};
        int *arr2{new int[101]};
        Agregate(4, 101, arr1, arr2);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception handled\n";
    }
    int *arr3{new int[5]{1, 2, 3, 4, 5}};
    int *arr4{new int[5]{6, 7, 8, 9, 10}};
    Agregate ag(5, 5, arr3, arr4);
    try
    {
        ag[100];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        ag[-3];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
