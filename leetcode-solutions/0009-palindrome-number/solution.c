#include <limits.h> 

bool isPalindrome(int x) {
    if (x < 0) return false;

    int rem = 0, num = x;

    while (x != 0) {
        int digit = x % 10;

        if (rem > (INT_MAX - digit) / 10) {
            return false;
        }

        rem = rem * 10 + digit;
        x /= 10;
    }

    return rem == num;
}
