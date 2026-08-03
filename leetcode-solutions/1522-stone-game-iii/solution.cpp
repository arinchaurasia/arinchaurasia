class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;
            int best = INT_MIN;
            for (int j = 0; j < 3 && i + j < n; j++) {
                sum += stoneValue[i + j];

                best = max(best, sum - dp[i + j + 1]);
            }
            dp[i] = best;
        }
        if (dp[0] > 0)
            return "Alice";

        if (dp[0] < 0)
            return "Bob";

        return "Tie";
    }
};
