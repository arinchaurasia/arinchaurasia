class Solution {
public:

int helper(int i,int j,vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if (j < 0 || j >= matrix.size()) return INT_MAX;
        if(i == matrix.size()-1) return matrix[i][j]; 
        if(dp[i][j] != INT_MAX) return dp[i][j];

    int down = helper(i+1,j,matrix,dp);
    int leftDiagonal = helper(i+1,j-1,matrix,dp);
    int rightDiagonal = helper(i+1,j+1,matrix,dp);
    return dp[i][j] = matrix[i][j]+min(down,min(leftDiagonal,rightDiagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int ans = INT_MAX;
        for(int j = 0; j<n;j++){
            ans = min(ans,helper(0,j,matrix,dp));
        }
        return ans;
    }
};
