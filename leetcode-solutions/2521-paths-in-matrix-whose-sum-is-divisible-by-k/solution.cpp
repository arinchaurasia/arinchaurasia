class Solution {
public:
    int const MOD = 1'000'000'007;
    int m, n, K;
    int helper(int i,int j,int rem,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(i>=m ||j>=n) return 0;
        if(dp[i][j][rem]!=-1) return dp[i][j][rem];

        int newRem= (rem+grid[i][j])%K;
        if(i==m-1 && j == n-1){
            return dp[i][j][rem] = (newRem ==0?1:0);
        }
        long long ways = 0;
        ways +=helper(i+1,j,newRem,grid,dp);
        ways +=helper(i,j+1,newRem,grid,dp);

        ways%=MOD;
        return dp[i][j][rem] = (int)ways;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        K = k;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return helper(0, 0, 0, grid, dp);
    }
};
