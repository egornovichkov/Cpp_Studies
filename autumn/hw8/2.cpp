#include <iostream>

class Food
{
public:
    Food() : m_freshness_days(0) {};
    Food(int freshness_days) : m_freshness_days(freshness_days) {};
    int get_freshness()
    {
        return m_freshness_days;
    }
protected:
    int m_freshness_days;
};

class Eggs : public Food
{
public:
    Eggs(int freshness_days) : Food(freshness_days){}
};

class Sugar : public Food
{
public:
    Sugar(int freshness_days) : Food(freshness_days){}
};

class Bakery : public Eggs, public Sugar
{
public:
    Bakery(int freshness_days1, int freshness_days2) : Eggs(freshness_days1), Sugar(freshness_days2){}
};

int main()
{
    
    Bakery cake(30, 2000);
    cake.get_freshness(); 
    // error: request for member 'get_freshness' is ambiguous
    // 38 |     cake.get_freshness();
    return 0;
}
