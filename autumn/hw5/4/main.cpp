#include <iostream>

#include "f.hpp"

// error: ld returned 1 exit status. Компилируем main.cpp и other.cpp, линковщик выдает ошибку: multiple definition of `x'.
// Ошибку можно исправить не определяя переменные в заголовочном файле (можно перенести в main.cpp). Поэтому нельзя писать описание 
// переменных и функций в заголовочных файлах (при повторном включении - нарушение ODR)

#include "g.hpp"

int main()
{

    std::cout << undefined_function(1);

// error: ld returned 1 exit status. Ошибка линковщика undefined reference to `undefined_function(int)'
// Препроцессор включает заголовочный g.hpp, компилятор видит объявление undefined_function и думает,
// что где-то далее будет определение, но его не встречается и линковщик в ступоре выдает ошибку. Исправляется созданием g.cpp,
// в котором эта функция определяется.

    return 0;
}
