#include <iostream>
#include <cstdlib> 
#include "palindrome.h"

int main() {
    long long n;
    std::cout << "enter n:" << std::endl;
    if (!(std::cin >> n)) {
        std::cout << "error, incorrect n" << std::endl;
        std::exit(1);
    }
    std::cout << "Double palindrome, not more than " << n << ":\n";
    for (long long i = 1; i <= n; i++) {
        if (isPalindrome(i)) {
            long long square = i * i;
            if (isPalindrome(square)) {
                std::cout << i << " square: " << square << ")\n";
            }
        }
    }
    return 0;
} 