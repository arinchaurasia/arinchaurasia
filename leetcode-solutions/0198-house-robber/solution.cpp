class Solution {
public:
    // Space Optimized

    // Bottom Up
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);
        // dp[i] -> max stolen money till i house
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(skip, steal);
        }
        return dp[n];
    }

    // Recursion + memo
    // int solve(vector<int>& nums, int i) {
    //     int n = nums.size();
    //     vector<int> dp(n + 1, -1);
    //     if (i >= n)
    //         return 0;
    //     if (dp[i] != -1)
    //         return dp[i];
    //     int steal = nums[i] + solve(nums, i + 2);
    //     int skip = solve(nums, i + 1);
    //     return dp[i] = max(steal, skip);
    // }

    // int rob(vector<int>& nums) {
    //     return solve(nums, 0);
    // }

    // Recursion
    // int solve(vector<int>& nums,int i){
    //     int n = nums.size();
    //     if(i>=n) return 0;
    //     int steal = nums[i]+solve( nums,i+2);
    //     int skip = solve(nums,i+1);
    //     return max(steal,skip);

    // }

    // int rob(vector<int>& nums){

    //     return solve(nums,0);
    // }
};
