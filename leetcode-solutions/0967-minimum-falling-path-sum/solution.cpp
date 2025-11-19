class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = dp[i + 1][j];

                int leftDiagonal = (j - 1 >= 0) ? dp[i + 1][j - 1] : INT_MAX;
                int rightDiagonal = (j + 1 < n) ? dp[i + 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min(down, min(leftDiagonal, rightDiagonal));
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};

