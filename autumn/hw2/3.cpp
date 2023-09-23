#include <iostream>
#include <vector>

int main()
{
    setlocale(LC_ALL, "");
    std::vector<int> arr;
    int n;
    std::wcout << L"Кол-во элементов ";
    std::cin >> n;
    std::wcout << L"Введите значения в массив в отсортированном порядке" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        int tmp_element;
        std::cin >> tmp_element;
        arr.push_back(tmp_element);
    }
    int key;
    std::wcout << std::endl
               << L"Введите искомый элемент: ";
    std::cin >> key;
    bool flag = false;
    int l = 0;
    int r = n - 1;
    int middle;

    while ((l <= r) && (flag != true))
    {
        middle = (l + r) / 2;
        if (arr.at(middle) == key)
        {
            flag = true;
        }
        if (arr.at(middle) > key)
        {
            r = middle - 1;
        }
        else
        {
            l = middle + 1;
        }
    }
    if (flag)
    {
        std::wcout << L"Индекс элемента " << key << L" в массиве равен: " << middle;
    }
    else
    {
        std::wcout << L"Элемент не найден";
    }
    return 0;
}