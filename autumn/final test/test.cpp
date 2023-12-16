#include <iostream>
#include <string>
#include <functional>
#include <cstdlib>

using function = std::function<char()>;

std::string password_gen(size_t length, function func)
{
    std::string password;
    for (int i = 0; i < length; ++i)
    {
        password.push_back(func());
    }
    return password;
}

int main()
{
    // 'A', ... 'Z'
    std::string set1;
    for (int i = 0; i < 26; ++i)
    {
        set1.push_back('A' + i);
    }
    std::cout << "set1: " << set1 << "\n";


    // 'a', ... 'z'
    std::string set2;
    for (int i = 0; i < 26; ++i)
    {
        set2.push_back('a' + i);
    }
    std::cout << "set2: " << set2 << "\n";


    // '0', ... '9'
    std::string set3;
    for (int i = 0; i < 10; ++i)
    {
        set3.push_back('0' + i);
    }
    std::cout << "set3: " << set3 << "\n";


    function symb_gen1 = [&set1](){return set1[(rand() % (26))];};
    function symb_gen2 = [&set2](){return set2[(rand() % (26))];};
    function symb_gen3 = [&set3](){return set3[(rand() % (10))];};

    std::cout << password_gen(5, symb_gen1) << "\n";
    std::cout << password_gen(8, symb_gen2) << "\n";
    std::cout << password_gen(6, symb_gen3) << "\n";
}
