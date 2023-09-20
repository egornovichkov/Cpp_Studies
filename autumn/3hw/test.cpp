#include <functional>
#include <iostream>

int main() {

const std::function<int(int)> lambda_factorial = [&lambda_factorial](int n){return n > 1 ? lambda_factorial(n-1) * n : 1;};
std::cout << lambda_factorial(3);

}