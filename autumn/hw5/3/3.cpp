#include <iostream>
#include <string>

class A
{

    friend class B;

private:
    std::string m_private = "Private data";
    class Secret
    {
        std::string m_secret = "Secret data!";
    };
    
    friend void func(A &, A::Secret &);
};

class B
{
    void print(A &obj, A::Secret &obj2)
    {
        std::cout << obj.m_private; // OK
        std::cout << obj2.m_secret; // error 'std::string A::Secret::m_secret' is private within this context
    }

void func(A &obj, A::Secret &obj2)
{
    std::cout << obj.m_private; // OK
    std::cout << obj2.m_secret; // error 'std::string A::Secret::m_secret' is private within this context
}
};

// Таким образом дружественные класс B и функция func могут получить приватные члены класса A, то есть могут обращаться к любым членам класса A.
// Однако из-за того, что отношение дружбы не сохраняется при переходе к вложенным классам, класс B и функция func не могут обратиться к членам
// вложенного в класс A класса Secret. Таким образом обеспечивается защита данных от сущностей-друзей. В случае если нужно защитить "почти все кроме..."
// можно во вложенный в класс A некоторый класс добавить сущностей друзей и члены, к которым друзьям нужно обращаться. Опять-таки благодаря тому, что
// отношение класса не сохраняется при переходе к внешним классам у друзей не будет доступа к остальным членам A.