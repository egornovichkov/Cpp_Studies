#include <utility>
#include <iostream>
#include <vector>
#include <memory>
#include "Customer.hpp"

class Product
{
public:
    friend Customer;

    Product(std::string &, double, std::vector<std::pair<Customer *, int>> &&arr_customers = {});

    void print();

private:
    std::string m_name;
    double m_price;
    std::vector<std::pair<std::shared_ptr<Customer>, int>> m_arr_customers;
    double m_income;
};