class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int row=m-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                if(row == m - 1 && col == n - 1) {
                    dp[row][col] = 1;
                }
                else{
                    dp[row][col] = dp[row+1][col] + dp[row][col+1];
                }
            }
        }
        return dp[0][0];
    }
};
