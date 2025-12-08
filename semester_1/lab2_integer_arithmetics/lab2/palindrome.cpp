#include "palindrome.h"

bool isPalindrome(long long num) {
    long long orig = num;
    long long rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return orig == rev;
}