#include <iostream>
#include <vector>
#include <algorithm>
struct Customer;

struct Product
{
    std::string m_name;
    double m_price;
    std::vector<Customer *> m_arr_customers;

    Product(std::string name, double price, std::vector<Customer *> arr_customers = {})
        : m_name(name), m_price(price), m_arr_customers(arr_customers)
    {
    }

    void print();

    ~Product()
    {
    }
};

struct Customer
{
    std::string m_name;
    double m_budget;
    double m_leftover;
    std::vector<Product *> m_arr_products;
    std::vector<int> m_arr_quantity;

    Customer(std::string name, double budget, double leftover = 0, std::vector<Product *> arr_products = {}, std::vector<int> arr_quantity = {})
        : m_name(name), m_budget(budget), m_leftover(budget), m_arr_products(arr_products), m_arr_quantity(arr_quantity)
    {
    }

    void bought(const std::vector<Product *> &arr_products, const std::vector<int> &arr_quantity)
    {
        for (size_t i = 0; i < arr_products.size(); ++i)
        {
            m_arr_quantity = arr_quantity;
            m_arr_products = arr_products;
            m_arr_products[i]->m_arr_customers.push_back(this);
            m_leftover -= (arr_products[i]->m_price) * arr_quantity[i];
        }
    }

    void print()
    {
        std::cout << "----------------------------";
        std::cout << "\nName: " << m_name;
        std::cout << "\nBudget: " << m_budget;
        std::cout << "\nBought: ";
        for (size_t i = 0; i < m_arr_products.size(); ++i)
            std::cout << m_arr_quantity[i] << "x " << m_arr_products[i]->m_name << " ";
        std::cout << "\nLeftover: " << m_leftover;
        std::cout << "\n----------------------------\n";
    }

    ~Customer()
    {
        std::cout << "...Destroyed all cards";
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
        for (size_t i = 0; i < m_arr_customers[j]->m_arr_products.size(); ++i)
        {
            if (m_arr_customers[j]->m_arr_products[i]->m_name == this->m_name)
            {
                std::cout << m_arr_customers[j]->m_arr_quantity[i] << "x by " << m_arr_customers[j]->m_name << " ";
            }
        }
    }
    std::cout << "\n----------------------------\n";
}

int main()
{

    // Создаем объекты продуктов
    std::cout << "Welcome to our shop's database. Firstly You have to input list of available products\n";
    std::cout << "Input number of products: ";
    size_t products_num;
    std::cin >> products_num;
    std::vector<Product *> arr_products;
    arr_products.reserve(products_num);
    for (size_t i = 0; i < products_num; ++i)
    {
        std::cout << "Input product's name: ";
        std::string input_name;
        std::cin >> input_name;
        std::cout << "Input product's price: ";
        double input_price;
        std::cin >> input_price;
        arr_products.push_back(new Product(input_name, input_price));
    }

    // Создаем объекты покупателей
    size_t customers_num;
    std::cout << "Input number of customers: ";
    std::cin >> customers_num;
    std::vector<Customer *> arr_customers;
    arr_customers.reserve(customers_num);
    for (size_t i = 0; i < customers_num; ++i)
    {
        std::cout << "Input customer's name: ";
        std::string input_name;
        std::cin >> input_name;
        std::cout << "Input customer's budget: ";
        double input_budget;
        std::cin >> input_budget;
        arr_customers.push_back(new Customer(input_name, input_budget));
    }

    // Добавляем покупателям покупки
    std::cout << "Now you can add products to customers (Input q to exit)\n";
    std::string name;
    std::vector<Product *> temp_products;
    std::vector<int> temp_quantity(products_num, 0);
    temp_products.reserve(products_num);
    while (name != "q")
    {
        std::cout << "Input customer's name: ";
        std::cin >> name;
        if (name == "q")
            break;
        size_t customer_index;
        for (size_t i = 0; i < arr_customers.size(); ++i)
        {
            if ((arr_customers[i]->m_name) == name)
                customer_index = i;
        }
        std::cout << "Now input products in format \"1Milk,2Eggs,1Bacon\" (Remember, no more than 9 products for one hands!): ";
        std::string goods;
        std::cin >> goods;
        std::string good;
        int quantity;
        for (char symb : goods)
        {
            if (symb >= '0' and symb <= '9')
            {
                quantity = symb - '0';
            }
            else if (symb == ',')
            {
                for (size_t i = 0; i < arr_products.size(); ++i)
                {
                    if (arr_products[i]->m_name == good)
                    {
                        temp_products.push_back(arr_products[i]);
                        temp_quantity.push_back(quantity);
                        quantity = 0;
                        good = {};
                    }
                }
            }
            else
            {
                good.push_back(symb);
            }
            for (size_t i = 0; i < arr_products.size(); ++i)
            {
                if ((arr_products[i]->m_name) == good)
                    temp_products.push_back(arr_products[i]);
            }
        }

        arr_customers[customer_index]->bought(temp_products, temp_quantity);
        name.clear();
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
                if ((arr_products[i]->m_name) == card)
                    arr_products[i]->print();
            }
        }
        else if (choice == "Customer")
        {
            std::cout << "Which customer's card would you like to see (Input name): ";
            std::cin >> card;
            for (size_t i = 0; i < arr_customers.size(); ++i)
            {
                if (arr_customers[i]->m_name == card)
                    arr_customers[i]->print();
            }
        }
        else if (choice == "q")
            break;
        else
            std::cout << "Wrong input\n";
    }

    // Освобождаем память
    for (auto elem : arr_customers)
        delete[] elem;
    return 0;
}
