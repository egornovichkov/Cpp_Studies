#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

int main()
{

    setlocale(LC_ALL, "");
    std::string input;
    std::string tmp;
    std::wcout << L"Введите строку: " << std::endl;
    getline(std::cin, input);
    std::vector<std::string> answer;
    std::string char_to_string;

    for (size_t index = 0; index < input.size(); ++index)
    {
        if (ispunct(input[index]))
        {
            if ((input[index] == '-') && (input[index + 1] != ' ') && !(ispunct(input[index + 1])) && (index < input.size() - 1))
            {
                tmp.push_back(input[index]);
            }
            else
            {
                if (tmp.size() > 0)
                {
                    answer.push_back(tmp);
                    tmp.clear();
                }
                char_to_string.push_back(input[index]);
                answer.push_back(char_to_string);
                char_to_string.clear();
            }
        }
        else if (input[index] == ' ')
        {
            if (tmp.size() > 0)
            {
                answer.push_back(tmp);
                tmp.clear();
            }
        }
        else
        {
            tmp.push_back(input[index]);
            if (tmp.size() > 0 && index == input.size() - 1)
            {
                answer.push_back(tmp);
                tmp.clear();
            }
        }
    }
    for (auto const& i : answer)
    {
        std::cout << i << std::endl;
    }
}