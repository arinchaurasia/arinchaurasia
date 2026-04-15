class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        int maxNum = 0;
        for(int x : nums)
            maxNum = max(maxNum, x);

        vector<int> points(maxNum + 1, 0);

        for(int x : nums)
            points[x] += x;

        int prev2 = 0;
        int prev1 = points[1];

        for(int i = 2; i <= maxNum; i++) {
            int curr = max(prev1, prev2 + points[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
