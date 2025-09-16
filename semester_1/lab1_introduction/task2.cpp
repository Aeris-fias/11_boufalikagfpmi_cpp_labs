#include <iostream>


 int main() {
  

    int n;
    std::cout <<  "input n: "<< std::endl;
   

    if (!(std::cin>>n)) {
        std::cout << "error, incorrect n)" << std::endl;
        std::exit(1);
        
    }

    int sum = 0;    
    int pr = 1; 

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
             
            sum += i;
        }
        else {
            
            pr *= i;
        }
    }

    std::cout << "sum from 1 to n " << n << ": " << sum << std::endl;
    std::cout << "product from 1 to n " << n << ": " << pr << std::endl;

    return 0;
}
