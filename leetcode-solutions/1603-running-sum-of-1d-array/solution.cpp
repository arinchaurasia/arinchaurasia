class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result(nums.size());
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            result[i] = sum;
        }

        return result;
    }
};
