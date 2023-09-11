#include <iostream>
#include <iomanip>

int main()
{
    std::string product_name;
    int product_price;
    bool cashback;
    int temp;
    std::cout << "Product's name: ";
    std::cin >> product_name;
    std::cout << "Product's price: ";
    std::cin >> product_price;
    std::cout << "Is cash-back available for this product? (true/false) ";
    std::cin >> std::boolalpha >> cashback;
    std::cout << "Maximum storing temperature: ";
    std::cin >> temp;

    std::cout << std::endl << product_name << std::endl;
    std::cout << std::setw(17) << std::setfill('.') << std::left << "Price:" << std::hex << std::printf("%07X", product_price) << std::endl;
    std::cout << std::setw(17) << std::setfill('.') << std::left << "Has cash-back:" << std::boolalpha << std::right << std::setw(8) << cashback << std::endl;
    std::cout << std::setw(17) << std::setfill('.') << std::left << "Max temperature:" << std::dec << std::showpos << std::right << std::setw(8) << temp << std::endl;
}
