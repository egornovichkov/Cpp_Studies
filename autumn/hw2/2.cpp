#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &arr)
{
    int i, j, key;
    for (i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    std::vector<int> arr;
    int size;
    std::wcout << L"Кол-во элементов ";
    std::cin >> size;
    arr.reserve(size);
    std::wcout << L"Введите значения в массив" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        int tmp_element;
        std::cin >> tmp_element;
        arr.push_back(tmp_element);
    }
    insertionSort(arr);
    for (auto i : arr)
    {
        std::cout << i << " ";
    }
    return 0;
}