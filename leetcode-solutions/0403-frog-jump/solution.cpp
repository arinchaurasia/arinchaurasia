class Solution {
public:
    bool helper(int prevJump, int ind, vector<int> &stones, map<pair<int,int>,int> &dp){
        if(ind == stones.size() - 1){
            return true;
        }
        if(dp.find({prevJump, ind}) != dp.end()) return dp[{prevJump, ind}];
        for(int i = ind+1; i < stones.size(); i++){
            if(stones[i] > stones[ind] + prevJump + 1) break;
            int curr = stones[i];
            if(curr == stones[ind] + prevJump + 1){
                if(helper(prevJump + 1, i, stones, dp)){
                    return dp[{prevJump, ind}] = true;
                }
            } else if(curr == stones[ind] + prevJump){
                if(helper(prevJump, i, stones, dp)){
                    return dp[{prevJump, ind}] =true;
                }
            } else if(curr == stones[ind] + prevJump - 1){
                if(helper(prevJump - 1, i, stones, dp)){
                    return dp[{prevJump, ind}] =true;
                }
            }
        }
        return dp[{prevJump, ind}] = false;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        map<pair<int,int>,int> dp;
        return helper(1, 1, stones, dp);
    }
};
