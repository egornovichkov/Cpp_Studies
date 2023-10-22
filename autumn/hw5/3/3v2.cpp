#include <iostream>
#include <string>

class A
{
public:
    class Allowed
    {
        friend void func(A &, Allowed &);
        friend class B;

        std::string m_private = "Private data";
    };

private:
    std::string m_secret = "Secret data!";
};

class B
{
    void print(A &obj, A::Allowed &obj2)
    {
        std::cout << obj2.m_private; // OK
        std::cout << obj.m_secret;   // error std::string A::m_secret is private within this context
    }
    void func(A &obj, A::Allowed &obj2)
    {
        std::cout << obj2.m_private; // OK
        std::cout << obj.m_secret;  // error std::string A::m_secret is private within this context
    }
};


// Иной способ реализации той же задачи, мой прошлый способ был плох если уже существует класс с большим количеством полей, этот вариант реализации
// лучше подходит под ситуацию когда необходимо предоставить доступ лишь к некоторым полям A сущностям-друзьям. Первый же подходит для "сокрытия" лишь
// некоторых полей