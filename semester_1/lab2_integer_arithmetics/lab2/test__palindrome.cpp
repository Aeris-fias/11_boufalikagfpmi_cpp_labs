#include <cassert>
#include <iostream>
#include "palindrome.h"

void test_negative_numbers() {
    assert(isPalindrome(-1) == false);
    assert(isPalindrome(-121) == false);
    assert(isPalindrome(-10) == false);
    std::cout << "test_negative_numbers passed\n";
}

void test_single_digit_numbers() {
    for (int x = 0; x <= 9; ++x) {
        assert(isPalindrome(x) == true);
    }
    std::cout << "test_single_digit_numbers passed\n";
}

void test_palindromes() {
    assert(isPalindrome(11) == true);
    assert(isPalindrome(121) == true);
    assert(isPalindrome(1221) == true);
    assert(isPalindrome(1001) == true);
    std::cout << "test_palindromes passed\n";
}

void test_non_palindromes() {
    assert(isPalindrome(10) == false);
    assert(isPalindrome(12) == false);
    assert(isPalindrome(123) == false);
    assert(isPalindrome(122) == false);
    std::cout << "test_non_palindromes passed\n";
}

void test_big_numbers() {
    assert(isPalindrome(1000001) == true);
    assert(isPalindrome(1234322) == false);
    std::cout << "test_big_numbers passed\n";
}

void test_double_palindromes() {
    int count = 0;
    for (long long i = 1; i <= 10; i++) {
        if (isPalindrome(i)) {
            long long square = i * i;
            if (isPalindrome(square)) {
                count++;
            }
        }
    }
    assert(count == 3);
    std::cout << "test_double_palindromes passed\n";
}
int main() {
    test_negative_numbers();
    test_single_digit_numbers();
    test_palindromes();
    test_non_palindromes();
    test_big_numbers();
    test_double_palindromes();

    std::cout << "All tests passed!\n";
    return 0;
}