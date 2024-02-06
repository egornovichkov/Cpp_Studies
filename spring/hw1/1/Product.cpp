#include "Product.hpp"

void Product::print()
{
    std::cout << "----------------------------";
    std::cout << "\nName: " << m_name;
    std::cout << "\nPrice: " << m_price;
    std::cout << "\nBought: ";
    for (size_t j = 0; j < m_arr_customers.size(); ++j)
    {
        for (size_t i = 0; i < m_arr_customers[j].first->m_arr_products.size(); ++i)
        {
            if (m_arr_customers[j].first->m_arr_products[i].first == this)
            {
                std::cout << m_arr_customers[j].first->m_arr_products[i].second << "x by " << m_arr_customers[j].first->m_name << " ";
                m_income += m_price * m_arr_customers[j].first->m_arr_products[i].second;
            }
        }
    }
    std::cout << "\nIncome: " << m_income;
    std::cout << "\n----------------------------\n";
}

Product::Product(std::string &name, double price, std::vector<std::pair<Customer *, int>> &&arr_customers)
    : m_name(name), m_price(price), m_arr_customers()
{
    for (size_t i = 0; i < arr_customers.size(); ++i)
    {
        m_arr_customers.push_back()
        std::pair<std::shared_ptr<Product>, int> product_pair{std::make_pair(std::make_shared<Product>(this), arr_customers[i].second)};
        arr_customers[i].first->m_arr_products.push_back(product_pair);
    }
}