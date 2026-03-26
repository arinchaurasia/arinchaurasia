class Solution {
public:
    bool checkHorizontal(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m <= 1) return false;

        long long totalSum = 0;
        vector<int> bot_counts(100005, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                totalSum += grid[i][j];
                bot_counts[grid[i][j]]++;
            }
        }

        long long topSum = 0;
        vector<int> top_counts(100005, 0);

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                topSum += grid[i][j];
                top_counts[grid[i][j]]++;
                bot_counts[grid[i][j]]--;
            }

            long long botSum = totalSum - topSum;

            if (topSum == botSum) return true;

            if (topSum > botSum) {
                long long target = topSum - botSum;
                if (target <= 100000 && target > 0) {
                    if (i == 0) {
                        if (target == grid[0][0] || target == grid[0][n - 1]) return true;
                    } else if (n == 1) {
                        if (target == grid[0][0] || target == grid[i][0]) return true;
                    } else {
                        if (top_counts[target] > 0) return true;
                    }
                }
            } else {
                long long target = botSum - topSum;
                if (target <= 100000 && target > 0) {
                    if (i == m - 2) {
                        if (target == grid[m - 1][0] || target == grid[m - 1][n - 1]) return true;
                    } else if (n == 1) {
                        if (target == grid[i + 1][0] || target == grid[m - 1][0]) return true;
                    } else {
                        if (bot_counts[target] > 0) return true;
                    }
                }
            }
        }
        return false;
    }

    vector<vector<int>> transpose(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                t[j][i] = grid[i][j];
            }
        }
        return t;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        return checkHorizontal(grid) || checkHorizontal(transpose(grid));
    }
};
