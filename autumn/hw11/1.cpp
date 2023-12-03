#include <iostream>
#include <cstring>

template <typename... Types>
size_t my_strlen(Types... lines)
{
    return ((strlen(lines) + ...));
}

template <typename First>
size_t my_strlen_recursive(First first)
{
    return strlen(first);
}

template <typename First, typename... Other>
size_t my_strlen_recursive(First first, Other... lines)
{
    return strlen(first) + my_strlen_recursive(lines...);
}

int main()
{
    std::cout << my_strlen("asd", "sssssss", "d") << "\n";
    std::cout << my_strlen_recursive("asd", "sssssss", "d") << "\n"; 

}
