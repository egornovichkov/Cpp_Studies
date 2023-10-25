#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

struct Customer;

struct Product
{
    std::string m_name;
    double m_price;
    std::vector<std::pair<Customer *, int>> m_arr_customers;
    double m_income;

    Product(std::string &name, double price, std::vector<std::pair<Customer *, int>> &&arr_customers = {});

    void print();
};

struct Customer
{
    std::string m_name;
    double m_budget;
    double m_leftover;
    std::vector<std::pair<Product *, int>> m_arr_products;

    Customer(std::string &name, double budget, std::vector<std::pair<Product *, int>> &&arr_products = {})
        : m_name(name), m_budget(budget), m_leftover(budget), m_arr_products(arr_products)
    {
        for (size_t i = 0; i < arr_products.size(); ++i)
        {
            std::pair<Customer *, int> customer_pair{std::make_pair(this, arr_products[i].second)};
            arr_products[i].first->m_arr_customers.push_back(customer_pair);
        }
    }

    void bought(const std::pair<Product *, int> &product)
    {
            m_arr_products.push_back(product);
            std::pair<Customer *, int> customer_pair{std::make_pair(this, product.second)};
            m_arr_products.back().first->m_arr_customers.push_back(customer_pair);
            m_leftover -= (product.first->m_price) * product.second;
    }

    void print()
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
};

// Пришлось вынести функцию вывода структуры после определения обеих структур, т.к. иначе функция-член Product::print() ссылается на неполный тип
// struct Customer. Forward declaration структуры Customer, который я использую эту проблему не решает, но зато все остальное работает нормально.
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
    : m_name(name), m_price(price), m_arr_customers(arr_customers)
{
    for (size_t i = 0; i < arr_customers.size(); ++i)
    {
        std::pair<Product *, int> product_pair{std::make_pair(this, arr_customers[i].second)};
        arr_customers[i].first->m_arr_products.push_back(product_pair);
    }
}

int main()
{
    // Создаем объекты продуктов
    std::cout << "Welcome to our shop's database. Firstly You have to input list of available products\n";
    std::cout << "Input number of products: ";
    size_t products_num;
    std::cin >> products_num;
    std::vector<Product> arr_products;
    arr_products.reserve(products_num);
    for (size_t i = 0; i < products_num; ++i)
    {
        std::cout << "Input product's name: ";
        std::string input_product_name;
        std::cin >> input_product_name;
        std::cout << "Input product's price: ";
        double input_price;
        std::cin >> input_price;
        arr_products.push_back(Product(input_product_name, input_price));
    }


    // Создаем объекты покупателей
    size_t customers_num;
    std::cout << "Input number of customers: ";
    std::cin >> customers_num;
    std::vector<Customer> arr_customers;
    arr_customers.reserve(customers_num);
    for (size_t i = 0; i < customers_num; ++i)
    {
        std::cout << "Input customer's name: ";
        std::string input_customer_name;
        std::cin >> input_customer_name;
        std::cout << "Input customer's budget: ";
        double input_budget;
        std::cin >> input_budget;
        arr_customers.push_back(Customer(input_customer_name, input_budget));
    }


    // Добавляем покупателям покупки
    std::cout << "Now you can add products to customers\n";
    std::string input;
    std::vector<std::pair<Product, int>> temp_products;
    while (input != "q")
    {
        std::cout << "Input customer's name (Input q to exit): ";
        std::cin >> input;
        if (input == "q")
            break;
        auto customer_it{std::find_if(begin(arr_customers), end(arr_customers), [&input](const auto c)
                                      { return c.m_name == input; })};
        if (customer_it != std::end(arr_customers))
        {
            std::cout << "Input number of bought products: ";
            size_t goods_num;
            std::cin >> goods_num;
        stop:
            for (size_t i = 0; i < goods_num; ++i)
            {
                std::cout << "Input product: ";
                std::string good;
                std::cin >> good;
                auto product_it{std::find_if(begin(arr_products), end(arr_products), [&good](const auto p)
                                             { return p.m_name == good; })};
                if (product_it != std::end(arr_products))
                {
                    std::cout << (*product_it).m_name << " " << (*product_it).m_price << "\n";
                    std::cout << (arr_products[0]).m_name << " " << arr_products[0].m_price << "\n";
                    std::cout << "Input quantity of this product: ";
                    int quantity;
                    std::cin >> quantity;
                    (*customer_it).bought(std::make_pair(&*product_it, quantity));
                }
                else
                {
                    std::cout << "Wrong product input\n";
                    // goto stop;
                }
            }
            input.clear();
            temp_products.clear();
        }
        else
            std::cout << "Wrong customer input\n";
    }

    // Смотрим интересующий объект продукта или покупателя
    while (true)
    {
        std::string choice;
        std::cout << "Which card would you like to see (Input Product or Customer or q to exit): ";
        std::cin >> choice;
        std::string card;
        if (choice == "Product")
        {
            std::cout << "Which product's card would you like to see (Input name): ";
            std::cin >> card;
            for (size_t i = 0; i < arr_products.size(); ++i)
            {
                if ((arr_products[i].m_name) == card)
                    arr_products[i].print();
            }
        }
        else if (choice == "Customer")
        {
            std::cout << "Which customer's card would you like to see (Input name): ";
            std::cin >> card;
            for (size_t i = 0; i < arr_customers.size(); ++i)
            {
                if (arr_customers[i].m_name == card)
                    arr_customers[i].print();
            }
        }
        else if (choice == "q")
            break;
        else
            std::cout << "Wrong input\n";
    }

    return 0;
}
