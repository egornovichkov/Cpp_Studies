#include "StupidSmartPointer.hpp"
#include "iostream"
#include "tuple"

int main()
{
    auto ssptr1 = StupidSmartPointer<double>();
    try
    {
        *(ssptr1);
    }
    catch (int)
    {
        std::cerr << "Dereferencing the nullpointer" << '\n';
    }
    ssptr1.~StupidSmartPointer();

    int *ptr1 = new int(5);
    int *ptr2 = new int(6);
    auto ssptr2 = StupidSmartPointer(ptr1);
    std::cout << "Raw ssptr2: " << ssptr2.get() << ", ssptr2 is not empty: " << std::boolalpha
              << bool(ssptr2) << ", Dereferenced value: " << *(ssptr2);
    ssptr2.reset(ptr2);
    std::cout << "\n" << "Dereferenced value: " << *(ssptr2) << "\n";
    ssptr2.release();

    auto ssptr3 = StupidSmartPointer<std::tuple<int, double, char>>();
    ssptr3.emplace(1, 2.3, 'a');
    std::cout << std::get<0>(*ssptr3) << " " << std::get<1>(*ssptr3) << " " << std::get<2>(*ssptr3);
}
