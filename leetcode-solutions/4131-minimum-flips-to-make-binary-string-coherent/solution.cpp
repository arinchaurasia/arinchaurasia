class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }

        int ans = INT_MAX;

        // 1) All zeros
        ans = min(ans, ones);

        // 2) All ones
        ans = min(ans, n - ones);

        // 3) Exactly one '1'
        ans = min(ans, (ones > 0 ? ones - 1 : 1));

        // 4) Pattern: 1 0...0 1
        if (n >= 2) {
            int cost = 0;

            if (s[0] == '0') cost++;
            if (s[n - 1] == '0') cost++;

            for (int i = 1; i < n - 1; i++) {
                if (s[i] == '1') cost++;
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};
