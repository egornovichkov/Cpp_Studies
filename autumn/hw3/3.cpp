#include <iostream>
#include <vector>
#include <algorithm>

int main()

{
    setlocale(LC_ALL, "");
    int size;
    int elem;
    std::vector<int> arr;
    std::wcout << L"Введите длину массива ";
    std::cin >> size;
    std::wcout << L"Введите значения в массив\n";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> elem;
        arr.push_back(elem);
    }
    std::sort(arr.begin(), arr.end(), [](int a, int b)
              { return a > b; });
    for (auto i : arr)
        std::cout << i << " ";
    std::cout << "\n";
    std::sort(arr.begin(), arr.end(), [](int a, int b)
              { return a < b; });
    for (const auto &i : arr)
        std::cout << i << " ";
}