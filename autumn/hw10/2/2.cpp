#include <iostream>
#include "DynArr.hpp"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DBG_NEW new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW

int main(int argc, char const *argv[])
{
    int *int_arr = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double *double_arr = new double[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char *char_arr = new char[10]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    // Работа спец. функций
    DynArr ArrInt(int_arr, 10);
    DynArr ArrDouble(double_arr, 10);
    DynArr ArrChar(char_arr, 10);
    std::cout << "ArrInt: " << ArrInt << "\n";
    std::cout << "ArrDouble: " << ArrDouble << "\n";
    std::cout << "ArrChar: " << ArrChar << "\n";
    DynArr ArrInt2(ArrInt);
    std::cout << "ArrInt: " << ArrInt << "\n";
    std::cout << "ArrInt2: " << ArrInt2 << "\n";
    DynArr ArrInt3(std::move(ArrInt));
    std::cout << "ArrInt: " << ArrInt << "\n";
    std::cout << "ArrInt3: " << ArrInt3 << "\n";
    DynArr ArrInt4 = ArrInt3;
    std::cout << "ArrInt3: " << ArrInt3 << "\n";
    std::cout << "ArrInt4: " << ArrInt4 << "\n";
    DynArr<int> ArrInt5;
    ArrInt5 = std::move(ArrInt4);
    std::cout << "ArrInt4: " << ArrInt4 << "\n";
    std::cout << "ArrInt5: " << ArrInt5 << "\n\n";

    // Работа публичных методов
    DynArr<int> ArrIntTest;
    ArrIntTest.resize(30);
    std::cout << "ArrIntTest.size(): " << ArrIntTest.size() << "\n";
    ArrIntTest.clear();
    for (int i = 0; i < 10; i++)
    {
        ArrIntTest.push_back(i);
    }
    std::cout << "ArrIntTest: " << ArrIntTest << "\n";
    ArrIntTest.pop_back();
    std::cout << "ArrIntTest: " << ArrIntTest << "\n";
    std::cout << "ArrIntTest[4]: " << ArrIntTest[4] << "\n";
    std::cout << std::boolalpha << ArrIntTest.is_empty() << "\n";
    std::cout << "ArrIntTest5: " << ArrInt5 << "\n";
    ArrIntTest.swap(ArrInt5);
    std::cout << "Arrays swapped:" << "\n";
    std::cout << "ArrIntTest: " << ArrIntTest << "\n";
    std::cout << "ArrInt5: " << ArrInt5 << "\n";

    // Демонстрация транзакционного поведения и обработки ошибок
    try
    {
        ArrInt5[10];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        ArrInt5[-1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    ArrInt5.resize(10000000000);
    std::cout << ArrInt5 << "\n";

    ArrInt5.clear();
    ArrInt5.pop_back();
    int* a = new int[10];
    _CrtDumpMemoryLeaks();
}
