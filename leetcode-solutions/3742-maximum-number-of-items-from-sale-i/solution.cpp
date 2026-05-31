class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bonus(n, 0);
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            vector<int> ndp = dp;
            int price = items[i][1];

            for (int b = 0; b + price <= budget; b++) {
                if (dp[b] == -1) {
                    continue;
                }
                ndp[b + price] = max(dp[b + price], dp[b] + 1 + bonus[i]);
            }
            for (int b = price; b <= budget; b++) {
                if (ndp[b - price] == -1) {
                    continue;
                }
                ndp[b] = max(ndp[b], ndp[b - price] + 1);
            }
            dp = move(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
