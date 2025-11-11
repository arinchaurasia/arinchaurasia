class Solution {
public:
   int countPaths(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if (grid[i][j] == 1) return 0;
    if (i == 0 && j == 0) return 1; //first position
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int up = 0, left = 0;
    if (i > 0) up = countPaths(i - 1, j, grid, dp);
    if (j > 0) left = countPaths(i, j - 1, grid, dp);

    return dp[i][j] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    if (grid[0][0] == 1)
        return 0;

    return countPaths(m - 1, n - 1, grid, dp);
}
};
