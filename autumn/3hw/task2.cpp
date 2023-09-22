#include <iostream>
#include <vector>

using vector = std::vector<int>;

void array_merge(vector &arr, vector &left_arr, vector &right_arr, bool mode);
void merge_sort(vector &arr, bool mode);

void merge_sort(vector &arr, bool mode)
{
    if (arr.size() <= 1)
    {
        return;
    }
    vector left_arr;
    vector right_arr;
    int mid = arr.size() / 2;
    for (auto i = 0; i < mid; ++i)
        left_arr.push_back(arr[i]);
    for (auto j = mid; j >= mid; ++j)
        right_arr.push_back(arr[j]);
    // merge_sort(left_arr, mode);
    // merge_sort(right_arr, mode);
    array_merge(arr, left_arr, right_arr, mode);
    return;
}

void array_merge(vector &arr, vector &left_arr, vector &right_arr, bool mode)
{
    vector temp_arr;
    if (mode == 0)
    {
        while ((left_arr.size() > 0) & (right_arr.size() > 0))
        {
            if (left_arr.front() > right_arr.front())
            {
                temp_arr.push_back(left_arr.front());
                left_arr.erase(left_arr.cbegin());
            }
            else
            {
                temp_arr.push_back(right_arr.front());
                right_arr.erase(right_arr.cbegin());
            }
        }
    }
    else
    {
        while ((left_arr.size() > 0) & (right_arr.size() > 0))
        {
            if (left_arr.front() < right_arr.front())
            {
                temp_arr.push_back(left_arr.front());
                left_arr.erase(left_arr.cbegin());
            }
            else
            {
                temp_arr.push_back(right_arr.front());
                right_arr.erase(right_arr.cbegin());
            }
        }
    }

    while (left_arr.size() > 0)
    {
        temp_arr.push_back(left_arr.front());
        left_arr.erase(left_arr.cbegin());
    }
    while (right_arr.size() > 0)
    {
        temp_arr.push_back(right_arr.front());
        left_arr.erase(right_arr.cbegin());
    }
    for (auto i : arr)
        arr[i] = temp_arr[i];
    return;
}

int main()
{
    setlocale(LC_ALL, "");
    char a;
    vector arr;
    bool mode;
    std::wcout << L"Введите массив, который хотите отсортировать (чтобы закончить ввод массива напишите q)\n";
    std::cin >> a;
    while (a != 'q')
    {
        int n = a - '0';
        arr.push_back(n);
        std::cin >> a;
    }
    std::cin.clear();
    std::wcout << L"Введите режим сортировки: 0 - по возрастанию, 1 - по убыванию\n";
    std::cin >> mode;
    for (auto &j : arr)
        std::cout << j << " ";
    merge_sort(arr, mode);
    for (auto &j : arr)
        std::cout << j << " ";
    return 0;
}
