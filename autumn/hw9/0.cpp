#include <iostream>

struct B
{
    B()
    {
        std::cout << "B()\n";
    }

    ~B()
    {
        std::cout << "~B()\n";
    }
};

struct A : public B
{
    A(int a) : B(), m_val(a)
    {
        std::cout << "A()\n";
        try
        {
            if (m_val < 0)
                throw -1;
        }
        catch (int &e)
        {
            std::cerr << e << '\n';
        }
        std::cout << "End of A()\n";
    }
    ~A()
    {
        std::cout << "~A()\n";
    }

    int m_val;
};

int main()
{
    A a(-3);
    return 0;
}
