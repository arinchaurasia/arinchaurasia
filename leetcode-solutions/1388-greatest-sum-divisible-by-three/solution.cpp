class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int num : nums) {
            vector<int> curr(dp);
            for (int r = 0; r < 3; r++) {
                int newSum = dp[r] + num;
                curr[newSum % 3] = max(curr[newSum % 3], newSum);
            }
            dp = curr;
        }
        return dp[0];
    }
};
