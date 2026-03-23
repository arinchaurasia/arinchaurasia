class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<long long>> max_dp(n, vector<long long>(m));
        vector<vector<long long>> min_dp(n, vector<long long>(m));

        max_dp[0][0] = min_dp[0][0] = grid[0][0];
        for (int j = 1; j < m; j++) {
            max_dp[0][j] = max_dp[0][j - 1] * grid[0][j];
            min_dp[0][j] = max_dp[0][j];
        }
        for (int i = 1; i < n; i++) {
            max_dp[i][0] = max_dp[i - 1][0] * grid[i][0];
            min_dp[i][0] = max_dp[i][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                long long val = grid[i][j];
                long long a = max_dp[i - 1][j] * val;
                long long b = min_dp[i - 1][j] * val;
                long long c = max_dp[i][j - 1] * val;
                long long d = min_dp[i][j - 1] * val;

                max_dp[i][j] = max({a, b, c, d});
                min_dp[i][j] = min({a, b, c, d});
            }
        }
        long long result = max_dp[n - 1][m - 1];
        if (result < 0)
            return -1;
        return result % 1000000007;
    }
};
