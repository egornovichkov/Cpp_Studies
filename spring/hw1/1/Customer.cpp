#include "Customer.hpp"

Customer::Customer(std::string &name, double budget, std::vector<std::pair<Product *, int>> &&arr_products = {})
    : m_name(name), m_budget(budget), m_leftover(budget), m_arr_products()
{
    for (size_t i = 0; i < arr_products.size(); ++i)
    {
        m_arr_products.push_back(std::make_pair((std::make_shared<Product>(arr_products[i].first)), arr_products[i].second));
        std::pair<std::shared_ptr<Customer>, int> customer_pair{std::make_pair(std::make_shared<Customer>(this), arr_products[i].second)};
        arr_products[i].first->m_arr_customers.push_back(customer_pair);
    }
}

void Customer::bought(const std::pair<Product *, int> &product)
{
    m_arr_products.push_back(std::make_pair(std::make_shared<Product>(product.first), product.second));
    std::pair<std::shared_ptr<Customer>, int> customer_pair{std::make_pair(std::make_shared<Customer>(this), product.second)};
    product.first->m_arr_customers.push_back(customer_pair);
    // m_arr_products.back().first->m_arr_customers.push_back(customer_pair);
    m_leftover -= (product.first->m_price) * product.second;
}

void Customer::print()
{
    std::cout << "----------------------------";
    std::cout << "\nName: " << m_name;
    std::cout << "\nBudget: " << m_budget;
    std::cout << "\nBought: ";
    for (size_t i = 0; i < m_arr_products.size(); ++i)
        std::cout << m_arr_products[i].second << "x " << m_arr_products[i].first->m_name << " ";
    std::cout << "\nLeftover: " << m_leftover;
    std::cout << "\n----------------------------\n";
}