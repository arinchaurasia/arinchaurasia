class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int score1 = 0, score2 = 0;
        int active = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                active = 3 - active;
            }
            if (i % 6 == 5) {
                active = 3 - active;
            }
            if (active == 1) {
                score1 += nums[i];
            } else {
                score2 += nums[i];
            }
        }
        return score1 - score2;
    }
};
