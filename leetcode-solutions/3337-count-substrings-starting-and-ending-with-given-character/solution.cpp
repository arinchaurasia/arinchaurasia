class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;
        long long count = 0;

        for (char ch : s) {
            if (ch == c) {
                count++;
                ans += count;
            }
        }

        return ans;
    }
};
