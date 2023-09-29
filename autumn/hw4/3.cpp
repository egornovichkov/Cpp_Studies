#include <iostream>


// Создание доп. структуры не увеличивает sizeof(Book). Если поместить поля Date в Book, Book на моем компьютере все равно занимает 12 байт 
// как и в данной реализации (мой компьютер выравнивает данные по границе в 4 байта, поместив поля Date в Book, sizeof(Book) мог бы быть равен 8,
// т.к. суммарно битовое поле занимало бы 58 бит но по каким-то причинам он все равно равен 12)
struct Date
{
    unsigned short m_day : 5;
    unsigned short m_month : 4;
    unsigned short m_year : 12;

    Date(unsigned short day, unsigned short month, unsigned short year)
    :   m_day(day), m_month(month), m_year(year)
    {
    }
};

struct Book
{
    unsigned short m_id : 14;
    unsigned short m_section : 4;
    unsigned short m_chapter : 7;
    unsigned short m_pages : 11;
    bool m_status : 1;
    Date m_date;

    Book(unsigned short id=0, unsigned short section=0, unsigned short chapter=0, unsigned short pages=0, bool status=0, Date date={0,0,0})
        :   m_id(id), m_section(section), m_chapter(chapter), m_pages(pages), m_status(status), m_date(date)
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
            std:: cout << "available";
        std::cout << "\nDate: " << m_date.m_day << "/" << m_date.m_month << "/" << m_date.m_year;
        std::cout << "\nSections: " << m_section;
        std::cout << "\nChapters: " << m_chapter;
        std::cout << "\nPages: " << m_pages;
        std::cout << "\n----------------------------\n";
    }

};

int main()
{
    Book Pirates_of_Carribean{9999, 5, 12, 1900, 1, {21, 1, 2023}};
    Pirates_of_Carribean.print();
    return 0;
}
