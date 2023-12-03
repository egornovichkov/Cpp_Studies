#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <tuple>

template <typename First, typename Second, typename... Args>
std::pair<First *, Second *> get_pointers(Args... args)
{
    First *first = new First();
    Second *second = new Second(args...);
    return std::pair(first, second);
}

template <typename First, typename Second>
void garbage_collector(std::pair<First *, Second *> ptrs)
{
    if (ptrs.first != nullptr)
        delete ptrs.first;
    if (ptrs.second != nullptr)
        delete ptrs.second;
}

int main()
{
    // Функция создает пару указателей на стринг и кортеж
    auto ptrs1 = get_pointers<std::string, std::tuple<char, int>, char, int>('a', 1);
    (*ptrs1.first) = "Hello";
    std::cout << (*ptrs1.first) << "\n";
    std::cout << std::get<0>(*ptrs1.second) << " " << std::get<1>(*ptrs1.second) << "\n\n";

    // Функция создает пару указателей. Первый указывает на пару <char, int>, второй указывает на вектор из векторов из даблов (матрица из даблов),
    // в конструктор вектора мы передаем уже созданную матрицу matrix
    std::vector<std::vector<double>> matrix{{1.1, 2.1}, {3.1, 4.1}};
    auto ptrs2 = get_pointers<std::pair<char, int>, std::vector<std::vector<double>>, std::vector<std::vector<double>>>(matrix);
    ptrs2.first->first = 'b';
    ptrs2.first->second = 2;
    std::cout << ptrs2.first->first << " " << ptrs2.first->second << "\n";
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            std::cout << (*ptrs2.second)[i][j] << " ";
        }
        std::cout << "\n";
    }

    garbage_collector(ptrs1);
    garbage_collector(ptrs2);
}
