class Solution {
public:
    bool validDigit(int n, int x) {
        int original = n;
        bool found = false;

        // Check digits except first
        while (n >= 10) {
            int digit = n % 10;
            if (digit == x) {
                found = true;
            }
            n /= 10;
        }

        // Now n is the first digit
        if (n == x)
            return false;

        return found;
    }
    // bool validDigit(int n, int x) {
    //     char d = x+'0';
    //     string s = to_string(n);
    //     if (s[0] == d) return false;
    //     for(int i = 0;i<s.length();i++){
    //         if(s[i] ==d){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};
