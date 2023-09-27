#include <iostream>
#include <vector>
struct Customer;

struct Product
{
    std::string m_name;
    double m_price;
    std::vector<const Customer *> m_arr_buyers;

    Product(std::string name, double price, std::vector<const Customer *> arr_buyers)
        : m_name(name), m_price(price), m_arr_buyers{arr_buyers}
    {
    }
};

struct Customer
{
    std::string m_name;
    double m_budget;
    std::vector<const Product *> m_arr_products;

    Customer(std::string name, double budget, std::vector<const Product *> arr_products)
        : m_name(name), m_budget(budget), m_arr_products{arr_products}
    {
    }
};

int main()
{
    Customer Dmitriy{Dmitriy, 1000, Eggs};
    Product Eggs{Eggs, 50, Dmitriy};
    return 0;
}
