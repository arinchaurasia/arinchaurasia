class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int fact[10];
        fact[0] = 1;
        for (int i = 1; i < 10; i++) {
            fact[i] = fact[i - 1] * i;
        }

        int temp = n;
        long long sumFact = 0;

        while (temp > 0) {
            int digit = temp % 10;
            sumFact += fact[digit];
            temp /= 10;
        }

        string s1 = to_string(n);
        string s2 = to_string(sumFact);

        if (s1.length() != s2.length())
            return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
    }
};
