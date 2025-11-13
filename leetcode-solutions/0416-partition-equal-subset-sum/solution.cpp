class Solution {
public:
    bool helper(int i,int target,vector <int> &nums,vector<vector<int>>&dp){
        if(target == 0) return true;
        if(i>=nums.size() || target < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool take = helper(i+1,target-nums[i],nums,dp);
        bool skip = helper(i+1,target,nums,dp);

        dp [i][target] = take || skip;
        return dp[i][target];
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int x : nums) total+=x;
        if(total % 2 != 0) return false;

        int target = total /2;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return helper(0,target,nums,dp);

    }
};
