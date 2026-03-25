class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return false;
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        vector<long long> rowSum(n, 0), colSum(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }
        if (total % 2 != 0)
            return false;
        long long target = total / 2;

        long long curr = 0;

        for (int i = 0; i < n - 1; i++) {
            curr += rowSum[i];
            if (curr == target)
                return true;
        }
        curr = 0;
        for (int j = 0; j < m - 1; j++) {
            curr += colSum[j];
            if (curr == target)
                return true;
        }
        return false;
    }
};
