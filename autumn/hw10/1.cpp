#include <iostream>

// Функция поиска my_find в динамическом массиве возвращает индекс элемента, равного заданному значению, если такого не встречается, возвращает -1
// Есть возможность задать свой унарный/бинарный компаратор передав функцию или лямбда-функцию

// Перегрузка шаблона функции для бинарных компараторов
template <typename T, typename Comp>
int my_find(const T *arr, size_t size, T val, Comp comp)
{
    for (size_t i = 0; i < size; i++)
    {
        if (comp(arr[i], val))
            return i;
    }
    return -1;
}

// Перегрузка шаблона функции для унарных компараторов (предикатов)
template <typename T>
int my_find(const T *arr, size_t size, T val, bool predicate(T))
{
    for (size_t i = 0; i < size; i++)
    {
        if (predicate(arr[i]))
            return i;
    }
    return -1;
}

// Перегрузка шаблона функции для отсутсвующего компаратора
template <typename T>
int my_find(const T *arr, size_t size, T val)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

// Компаратор (равенство)
bool equal(double a, double b) { return a == b ? 1 : 0; }

// Предикат (меньше нуля)
bool less_than_zero(double a) { return a < 0; }

// Компаратор (равенство по модулю 2)
bool modular_2_equal(int a, int b) { return ((a % 2) == (b % 2)) ? 1 : 0; }

int main()
{
    // Массивы могут быть как константными так и неконстантными
    double *double_arr = new double[5]{1, 2, 3, 4, 5};
    const char *char_arr = new char[4]{'a', 'b', 'c', 'd'};
    int *int_arr = new int[4]{1, 1, 2, 1};
    
    std::cout << my_find(double_arr, 5, 4.0, equal) << "\n";
    std::cout << my_find(double_arr, 5, 4.0, less_than_zero) << "\n";
    std::cout << my_find(char_arr, 4, 'b', [](char a, char b) { return a == b ? 1 : 0; }) << "\n";
    std::cout << my_find(int_arr, 4, 2, modular_2_equal) << "\n";
    std::cout << my_find(int_arr, 4, 2);

    delete[] (double_arr);
    delete[] (char_arr);
    delete[] (int_arr);
}
