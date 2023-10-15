#include <iostream>
#include <cmath>
#include <stdexcept>

int validate(int value, int size)
{
    
    if (value > size)
        throw std::out_of_range("Invalid value, check acceptable range");
    return value;
}

int validate(int value, int lower_boundary, int upper_boundary)
{
    if (value > upper_boundary or value < lower_boundary)
        throw std::out_of_range("Invalid value, check acceptable range");
    return value;
}

// Создание доп. структуры не увеличивает sizeof(Book). Если поместить поля Date в Book, Book на моем компьютере все равно занимает 12 байт
// как и в данной реализации (мой компьютер выравнивает данные по границе в 4 байта, поместив поля Date в Book, sizeof(Book) мог бы быть равен 8,
// т.к. суммарно битовое поле занимало бы 58 бит но по каким-то причинам он все равно равен 12)
struct Date
{

    enum class DateFieldMaxSize
    {
        field1 = 31,
        field2 = 12,
        field3 = 3000
    };

    unsigned short m_day : 5;
    unsigned short m_month : 4;
    unsigned short m_year : 12;

    Date(unsigned short day, unsigned short month, unsigned short year)
        : m_day(validate(day, static_cast<int>(DateFieldMaxSize::field1), 1)),
        m_month(validate(month, static_cast<int>(DateFieldMaxSize::field2), 1)), 
        m_year(validate(year, static_cast<int>(DateFieldMaxSize::field3)))
    {
    }
};

struct Book
{

    enum class BookFieldMaxSize
    {
        field1 = 10000,
        field2 = 10,
        field3 = 100,
        field4 = 2000,
        field5 = 1
    };

    unsigned short m_id : 14;
    unsigned short m_section : 4;
    unsigned short m_chapter : 7;
    unsigned short m_pages : 11;
    bool m_status : 1;
    Date m_date;

    Book(unsigned short id = 0, unsigned short section = 0, unsigned short chapter = 0, unsigned short pages = 0, bool status = 0, Date date = {0, 0, 0})
        : m_id(validate(id, static_cast<int>(BookFieldMaxSize::field1))), 
        m_section(validate(section, static_cast<int>(BookFieldMaxSize::field2))), 
        m_chapter(validate(chapter, static_cast<int>(BookFieldMaxSize::field3))), 
        m_pages(validate(pages, static_cast<int>(BookFieldMaxSize::field4))), 
        m_status(validate(status, static_cast<int>(BookFieldMaxSize::field5))), 
        m_date(date)
    {
    }

    ~Book()
    {
        std::cout << "...Book deleted";
    }

    void print()
    {
        std::cout << "----------------------------";
        std::cout << "\nID: " << m_id;
        std::cout << "\nStatus: ";
        if (m_status)
            std::cout << "On hands";
        else
            std::cout << "available";
        std::cout << "\nDate: " << m_date.m_day << "/" << m_date.m_month << "/" << m_date.m_year;
        std::cout << "\nSections: " << m_section;
        std::cout << "\nChapters: " << m_chapter;
        std::cout << "\nPages: " << m_pages;
        std::cout << "\n----------------------------\n";
    }
};

int main()
{
    Book Pirates_of_Carribean{10000, 5, 12, 1900, 1, {21, 1, 2023}};
    Pirates_of_Carribean.print();
    Book WrongDateBook1{0, 0, 0, 0, 0, {32, 1, 0}};
    // Book WrongDateBook2{0, 0, 0, 0, 0, {1, 0, 0}};
    // Book WrongPagesBook{0, 0, 0, 2014, 0, {0, 0, 0}};
    return 0;
}
