class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i == triangle.size()-1) return triangle[i][j]; 
        if(dp[i][j] != INT_MIN) {
            return dp[i][j];
    }
    int down = helper(i+1,j,triangle,dp);
    int diagonal = helper(i+1,j+1,triangle,dp);
    return dp[i][j] = triangle[i][j]+min(down,diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        return helper(0,0,triangle,dp);
    }
};
