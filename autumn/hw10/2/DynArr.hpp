#include <iostream>
#include "Exceptions/logic_error.hpp"
#include "Exceptions/out_of_range.hpp"

// Я постарался реализовать транзакционное поведение класса, откат к состоянию производится при помощи метода recovery_from_backup() в блоках catch
// При этом всегда (кроме случая с неконстантным оператором[]) бэкап-массив поддерживается в актуальном состоянии при помощи метода backup()
template <typename T>
class DynArr
{
public:
    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const DynArr<U> &);

    template <typename U>
    friend std::istream &operator>>(std::istream &, DynArr<U> &);

    DynArr() noexcept;

    DynArr(T *arr, size_t size) noexcept;

    DynArr(const DynArr &) noexcept;

    DynArr(DynArr &&) noexcept;

    DynArr &operator=(const DynArr &) noexcept;

    DynArr &operator=(DynArr &&) noexcept;

    ~DynArr() noexcept;

    T &operator[](size_t);

    const T &operator[](size_t) const;

    void resize(size_t size);

    void push_back(const T &);

    void pop_back();

    void clear() noexcept;

    bool is_empty() const noexcept;

    size_t size() const noexcept;

    void swap(DynArr &) noexcept;

private:
    // Копирование основного массива в бэкап массив
    void backup() noexcept;

    // Восстановление основного массива из бэкап массива
    void recovery_from_backup() noexcept;

    size_t static validate_index(int, size_t);

    T *m_arr;
    T *m_arr_backup;
    size_t m_size;
};

#include "DynArr.ipp"