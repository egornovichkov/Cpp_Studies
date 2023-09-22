#include <iostream>
#include <algorithm>

int main()
{
    int size1;
    int elem;
    std::cout << "Input size of array: ";
    std::cin >> size1;
    int *ptr1 = new int[size1];
    std::cout << "Input elements of array:\n";
    for (int i = 0; i < size1; ++i)
    {
        std::cin >> elem;
        ptr1[i] = elem;
    }
    int size2;
    std::cout << "Input new size of array: ";
    std::cin >> size2;
    int *ptr2 = new int[size2];
    for (int i = 0; i < std::min(size1, size2); ++i)
        ptr2[i] = ptr1[i];
    if (size2 > size1)
    {
        std::cout << "Add more elements to array: ";
        for (int i = 0; i < size2 - size1; ++i)
        {
            std::cin >> elem;
            ptr2[size1 + i] = elem;
        }
    }
    int sum = 0;
    for (int i = 0; i < size2; ++i)
        sum += ptr2[i];
    std::cout << "Sum of elements is: " << sum;

    return 0;
}