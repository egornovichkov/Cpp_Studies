#include <iostream>
#include <vector>
struct Customer;

struct Product
{
    std::string m_name;
    double m_price;
    std::vector<Customer *> m_arr_buyers;

    Product(std::string name, double price, std::vector<Customer *> arr_buyers = {})
        : m_name(name), m_price(price), m_arr_buyers(arr_buyers)
    {
    }

    void print();
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
            m_arr_quantity.push_back(arr_quantity[i]);
            m_arr_products.push_back(arr_products[i]);
            m_arr_products[i]->m_arr_buyers.push_back(this);
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
    }
};

// Пришлось вынести функцию вывода структуры после определения обеих структур, т.к. иначе функция-член Product::print() ссылается на неполный тип
// struct Customer. Forward declaration структуры Customer, который я использую эту проблему не решает, но зато все остальное работает нормально.
// Я бы сделал обе структуры в отдельных файлах и включил директивой #include, но не уверен, что в этом суть задания.
void Product::print()
{
    std::cout << "----------------------------";
    std::cout << "\nName: " << m_name;
    std::cout << "\nPrice: " << m_price;
    std::cout << "\nBought: ";
    for (size_t i = 0; i < m_arr_buyers.size(); ++i)
        std::cout << m_arr_buyers[i]->m_arr_quantity[i] << "x by " << m_arr_buyers[i]->m_name << " ";
    std::cout << "\n----------------------------\n";
}

int main()
{
    Customer *Dima = new Customer("Dima", 1000);
    Customer *Sveta = new Customer("Sveta", 150);
    Customer *Pavel = new Customer("Pavel", 13000);
    Product *Eggs = new Product("Eggs", 100);
    Product *Milk = new Product("Milk", 80);
    Product *Bacon = new Product("Bacon", 150);
    Product *Cereals = new Product("Cereals", 180);

    Dima->bought({Eggs, Milk}, {1, 1});
    // Sveta->bought({Bacon}, {1});
    // Pavel->bought({Milk, Cereals, Eggs}, {1, 1, 1});

    Dima->print();
    Eggs->print();

    return 0;
}
