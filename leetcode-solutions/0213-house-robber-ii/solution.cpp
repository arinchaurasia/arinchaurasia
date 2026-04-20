class Solution {
public:
    // Bottom Up
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);
        // dp[i] -> max stolen money till i house
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 1; i <= n - 1; i++) {
            int skip = dp[i - 1];
            int steal = nums[i - 1] + (i - 2 >= 0 ? dp[i - 2] : 0);
            dp[i] = max(skip, steal);
        }
        int result1 = dp[n - 1];
        dp.clear();

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            int steal = nums[i - 1] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int skip = dp[i - 1];
            dp[i] = max(skip, steal);
        }
        int result2 = dp[n];

        return max(result1, result2);
    }

    // recursion + memo
    // int solve(vector<int>& nums, int i, int n, vector<int>& dp) {
    //     if (i > n)
    //         return 0;

    //     if (dp[i] != -1)
    //         return dp[i];

    //     int steal = nums[i] + solve(nums, i + 2, n, dp);
    //     int skip = solve(nums, i + 1, n, dp);

    //     return dp[i] = max(steal, skip);
    // }

    // int rob(vector<int>& nums) {
    //     int n = nums.size();

    //     if (n == 1)
    //         return nums[0];
    //     if (n == 2)
    //         return max(nums[0], nums[1]);

    //     vector<int> dp1(n, -1);
    //     vector<int> dp2(n, -1);

    //     int take_0th = solve(nums, 0, n - 2, dp1);
    //     int take_1st = solve(nums, 1, n - 1, dp2);

    //     return max(take_0th, take_1st);
    // }
};
