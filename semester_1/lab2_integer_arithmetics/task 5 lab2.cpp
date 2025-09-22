#include <iostream>


bool isPalindrome(long long num) {
    long long orig = num;
    long long rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10; 
        num /= 10;
    }
    return orig == rev; 
}
int main() {
    long long n;
    std::cout << "enter n:" << std::endl;
    if (!(std::cin >> n)) {
        std::cout << "error, incorrect n)" << std::endl;
        std::exit(1);
    }
    std::cout << "Double palindrom, not more than " << n << ":\n";
    for (long long i = 1; i <= n; i++) {
        if (isPalindrome(i)) {
            long long square = i * i;
            if (isPalindrome(square)) {
                std::cout << i << " (square: " << square << ")\n";
            }
        }
    }
    return 0;
}