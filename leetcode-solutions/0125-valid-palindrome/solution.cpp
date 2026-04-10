class Solution {
public:
    bool palindrome(int i, string& s) {
        int n = s.length();
        if (i >= n / 2)
            return true;
        if (s[i] != s[n - i - 1])
            return false;
        return palindrome(i + 1, s);
    }
    bool isPalindrome(string s) {
        string clean = "";
        for (char c : s) {
            if (isalnum(c)) {
                clean += tolower(c);
            }
        }
        return palindrome(0, clean);
    }
};

