#include <iostream>


 int main() {
  

    int n;
    std::cout <<  "input n: "<< std::endl;
    std::cin >> n;

    if (!(std::cin>>n)) {
        std::cout << "error, incorrect n)" << std::endl;
        std::exit(1);
        
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
