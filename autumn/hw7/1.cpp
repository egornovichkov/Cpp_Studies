#include <iostream>
#include <string>

class Agregate
{
public:
    friend std::ostream &operator<<(std::ostream &, const Agregate &);

    Agregate() : m_size1(10), m_size2(10), m_ptr1(nullptr), m_ptr2(nullptr), m_string("Default")
    {
        std::cout << "Agregate()\n";

        m_ptr1 = new int[m_size1];
        m_ptr2 = new int[m_size2];

        for (size_t i = 0; i < m_size1; i++)
        {
            m_ptr1[i] = 0;
        }

        for (size_t i = 0; i < m_size2; i++)
        {
            m_ptr2[i] = 0;
        }
    }

    Agregate(size_t size1, size_t size2, int *arr1, int *arr2, const std::string &str)
        : m_size1(size1), m_size2(size2), m_ptr1(arr1), m_ptr2(arr2), m_string(m_string) {}

    Agregate(const Agregate &other) : m_size1(0), m_size2(0), m_ptr1(nullptr), m_ptr2(nullptr), m_string("")
    {

        std::cout << "Agregate(const Agregate&)\n";

        if (&other == this)
        {
            return;
        }
        if (!other.is_empty1())
        {
            m_size1 = other.m_size1;
            m_ptr1 = new int[m_size1];
            for (size_t i = 0; i < m_size1; i++)
            {
                m_ptr1[i] = other.m_ptr1[i];
            }
        }
        if (!other.is_empty2())
        {
            m_size2 = other.m_size2;
            m_ptr1 = new int[m_size2];
            for (size_t i = 0; i < m_size2; i++)
            {
                m_ptr2[i] = other.m_ptr2[i];
            }
        }

        m_string = other.m_string;
    }

    Agregate(Agregate &&other) : m_size1(0), m_size2(0), m_ptr1(nullptr), m_ptr2(nullptr), m_string("")
    {
        std::cout << "Agregate(Agregate&&)\n";

        if (&other == this)
        {
            return;
        }

        if (!other.is_empty1())
        {
            m_size1 = other.m_size1;
            m_ptr1 = other.m_ptr1;
            other.m_ptr1 = nullptr;
            other.m_size1 = 0;
        }

        if (!other.is_empty2())
        {
            m_size2 = other.m_size2;
            m_ptr2 = other.m_ptr2;
            other.m_ptr2 = nullptr;
            other.m_size2 = 0;
        }

        m_string = std::move(other.m_string);
    }

    Agregate &operator=(const Agregate &other)
    {
        std::cout << "operator=(const Agregate&)\n";

        if (&other == this)
        {
            return *this;
        }

        if (!this->is_empty1())
        {
            delete[] m_ptr1;
            m_ptr1 = nullptr;
            m_size1 = 0;
        }

        if (!this->is_empty2())
        {
            delete[] m_ptr2;
            m_ptr2 = nullptr;
            m_size2 = 0;
        }

        if (!other.is_empty1())
        {
            m_ptr1 = new int[other.m_size1];
            for (size_t i = 0; i < other.m_size1; i++)
            {
                m_ptr1[i] = other.m_ptr1[i];
            }
        }

        if (!other.is_empty2())
        {
            m_ptr2 = new int[other.m_size2];
            for (size_t i = 0; i < other.m_size2; i++)
            {
                m_ptr2[i] = other.m_ptr2[i];
            }
        }

        m_string = other.m_string;
        return *this;
    }

    Agregate &operator=(Agregate &&other)
    {
        std::cout << "operator=(Agregate&&)\n";

        if (&other == this)
        {
            return *this;
        }

        if (!this->is_empty1())
        {
            delete[] m_ptr1;
            m_ptr1 = nullptr;
            m_size1 = 0;
        }

        if (!this->is_empty2())
        {
            delete[] m_ptr2;
            m_ptr2 = nullptr;
            m_size2 = 0;
        }

        if (!other.is_empty1())
        {
            m_ptr1 = other.m_ptr1;
            m_size1 = other.m_size1;
            other.m_ptr1 = nullptr;
            other.m_size1 = 0;
        }

        if (!other.is_empty2())
        {
            m_ptr2 = other.m_ptr2;
            m_size2 = other.m_size2;
            other.m_ptr2 = nullptr;
            other.m_size2 = 0;
        }

        m_string = std::move(other.m_string);
    }

    ~Agregate()
    {
        std::cout << "~Agregate()\n";

        if (!this->is_empty1())
        {
            m_size1 = 0;
            delete[] m_ptr1;
        }

        if (!this->is_empty2())
        {
            m_size2 = 0;
            delete[] m_ptr2;
        }

        m_string.clear();
    }

    int &operator[](size_t index)
    {
        if (index >= m_size1 + m_size2)
        {
            std::cout << "Out of range\n";
            exit(2);
        }
        if (index < m_size1)
        {
            return m_ptr1[index];
        }
        else
            return m_ptr2[index];
    }

    bool is_empty1() const
    {
        if (m_size1 == 0)
            return 1;
        return 0;
    }

    bool is_empty2() const
    {
        if (m_size2 == 0)
            return 1;
        return 0;
    }

private:
    size_t m_size1;
    size_t m_size2;
    int *m_ptr1;
    int *m_ptr2;
    std::string m_string;
};

std::ostream &operator<<(std::ostream &out, const Agregate &rhs)
{
    out << "Array1: ";
    if (rhs.m_size1 == 0)
    {
        out << "empty";
    }
    else
    {
        for (size_t i = 0; i < rhs.m_size1; i++)
        {
            out << rhs.m_ptr1[i] << " ";
        }
    }
    out << "\n"
        << "Array2: ";
    if (rhs.m_size2 == 0)
    {
        out << "empty";
    }
    else
    {
        for (size_t i = 0; i < rhs.m_size2; i++)
        {
            out << rhs.m_ptr2[i] << " ";
        }
    }
    out << "\n"
        << "String: ";
    if (rhs.m_string.empty())
    {
        out << "empty";
    }
    else
    {
        out << rhs.m_string;
    }
    out << "\n";
    return out;
}

int main()
{
    Agregate test_obj;
    for (size_t i = 0; i < 20; i++)
    {
        test_obj[i] = i;
    }
    std::cout << "test_obj:\n"
              << test_obj;
    Agregate obj1(test_obj);
    std::cout << "obj1:\n"
              << obj1;
    Agregate obj2(std::move(test_obj));
    std::cout << "obj2:"
              << "\n"
              << obj2;
    std::cout << "test_obj is empty:\n"
              << test_obj << "\n";
    Agregate test_obj2;
    for (size_t i = 0; i < 20; i++)
    {
        test_obj2[i] = i;
    }
    Agregate obj3;
    obj3 = test_obj2;
    std::cout << obj3;
    std::cout << "test_obj2 is empty" << test_obj2;

    return 0;
}
