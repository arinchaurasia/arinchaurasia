class Solution {
public:
    int helper(vector<int> &nums, int ind,vector<int> &dp){
        if(ind == nums.size() - 1){
            return nums[ind];
        } else if(ind >= nums.size()){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
            return dp[ind] = max(helper(nums, ind+1, dp), nums[ind] + helper(nums, ind + 2, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return helper(nums, 0, dp);
    }
};
