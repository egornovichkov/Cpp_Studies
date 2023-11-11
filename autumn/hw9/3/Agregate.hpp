#include <iostream>
#include <string>

class Agregate
{
public:
    friend std::ostream &operator<<(std::ostream &, const Agregate &);

    Agregate();

    Agregate(size_t, size_t, int *, int *, const std::string &);

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