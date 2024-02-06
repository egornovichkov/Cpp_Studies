#pragma once
#include <utility>
#include <iostream>
#include <vector>
#include "Product.hpp"

class Customer
{
public:
    friend Product;

    Customer(std::string &, double, std::vector<std::pair<Product *, int>> &&arr_products = {});

    void bought(const std::pair<Product *, int> &);

    void print();

private:
    std::string m_name;
    double m_budget;
    double m_leftover;
    std::vector<std::pair<std::shared_ptr<Product>, int>> m_arr_products;
};
