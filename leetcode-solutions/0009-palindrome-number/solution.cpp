class Solution {
public:
    bool isPalindrome(int x) {
        int rem, rev = 0;
        int num = x;
        while (x != 0) {
            if (x < 0)
                return false;
            rem = x % 10;

            if (rev > INT_MAX / 10 )
                return false;

            rev = (rev * 10) + rem;
            x = x / 10;
        }
        return rev==num;
    }
};
