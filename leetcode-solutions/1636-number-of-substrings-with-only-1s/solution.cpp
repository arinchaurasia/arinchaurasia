class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long ans = 0, curr = 0;

        for (char c : s) {
            if (c == '1') {
                curr++;
                ans = (ans + curr) % MOD;
            } else {
                curr = 0;
            }
        }
        return ans;
    }
};
