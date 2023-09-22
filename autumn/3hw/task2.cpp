#include <iostream>
#include <vector>

using vector = std::vector<int>;

void array_merge(vector &arr, int start, int end, bool mode);
void merge_sort(vector &arr, int start, int end, bool mode);

void merge_sort(vector &arr, int start, int end, bool mode)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid, mode);
        merge_sort(arr, mid + 1, end, mode);
        array_merge(arr, start, end, mode);
    }
    return;
}

void array_merge(vector &arr, int start, int end, bool mode)
{
    vector temp_arr = arr;
    int mid = (start + end) / 2;
    int left_first = start;    // Индекс первого элемента левой половины
    int right_first = mid + 1; // Индекс первого элемента правой половины
    if (mode == 0)
    {
        for (int i = left_first; i <= end; ++i)
        {
            // Левая часть вектора левее середины и (либо правая половина вектора пустая, либо первый элемент левого вектора меньше 
            // первого элемента правого вектора)
            if ((left_first <= mid) && ((right_first > end) || (arr[left_first] < arr[right_first]))) 
            {
                temp_arr[i] = arr[left_first];
                ++left_first;
            }
            else
            {
                temp_arr[i] = arr[right_first];
                ++right_first;
            }
        }
    }
    else
    {
        for (int i = left_first; i <= end; ++i)
        {
            if ((left_first <= mid) && ((right_first > end) || (arr[left_first] > arr[right_first])))
            {
                temp_arr[i] = arr[left_first];
                ++left_first;
            }
            else
            {
                temp_arr[i] = arr[right_first];
                ++right_first;
            }
        }
    }

    for (int i = start; i <= end; ++i)
        arr[i] = temp_arr[i];
    return;
}

int main()
{
    setlocale(LC_ALL, "");
    vector arr;
    bool mode;
    int size;
    int elem;
    std::wcout << L"Введите длину массива ";
    std::cin >> size;
    std::wcout << L"Введите значения в массив\n";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> elem;
        arr.push_back(elem);
    }
    std::wcout << L"Введите режим сортировки: 0 - по возрастанию, 1 - по убыванию\n";
    std::cin >> mode;
    for (auto &j : arr)
        std::cout << j << " ";
    std::cout << "\n";
    merge_sort(arr, 0, size - 1, mode);
    for (auto &j : arr)
        std::cout << j << " ";
    return 0;
}
