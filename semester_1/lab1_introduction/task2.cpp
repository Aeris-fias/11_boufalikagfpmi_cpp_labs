#include <iostream>


 int main() {
    setlocale(LC_ALL, "Rus");

    int n;
    std::cout <<  "input n: "<< std::endl;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "error, n must be > 0)" << std::endl;
        
    }

    int sumEven = 0;    
    int productOdd = 1; 

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            
            sumEven += i;
        }
        else {
            
            productOdd *= i;
        }
    }

    std::cout << "sum from 1 to n " << n << ": " << sumEven << std::endl;
    std::cout << "product from 1 to n " << n << ": " << productOdd << std::endl;

    return 0;
}
