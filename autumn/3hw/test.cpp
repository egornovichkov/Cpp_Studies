#include <iostream>
#include <vector>

using vector = std::vector<int>;

void merge_sort(vector &arr, bool mode)
{
    int mode = 0;
    vector arr = {2, 1};
    vector left_arr;
    vector right_arr;
    int mid = arr.size() / 2;
    for (auto i = 0; i < mid; ++i)
        left_arr.push_back(arr[i]);
    for (auto j = mid; j >= mid; ++j)
        right_arr.push_back(arr[j]);
    merge_sort(left_arr, mode);
    merge_sort(right_arr, mode);
    // array_merge(arr, left_arr, right_arr, mode);
}