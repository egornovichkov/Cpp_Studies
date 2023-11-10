#include <iostream>
#include <string>

class Agregate
{
public:
    friend std::ostream &operator<<(std::ostream &, const Agregate &);

    Agregate();

    Agregate(size_t size1, size_t size2, int *arr1, int *arr2, const std::string &str)
        : m_size1(size1), m_size2(size2), m_ptr1(arr1), m_ptr2(arr2), m_string(m_string) {}

    Agregate(const Agregate &);

    Agregate(Agregate &&);

    Agregate &operator=(const Agregate &);

    Agregate &operator=(Agregate &&);

    ~Agregate();

    int &operator[](size_t);

    bool is_empty1() const;

    bool is_empty2() const;

    void set_string(const std::string &);

private:
    size_t m_size1;
    size_t m_size2;
    int *m_ptr1;
    int *m_ptr2;
    std::string m_string;
};