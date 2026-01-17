class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> num = nums;

        unordered_set<int> values;

        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                values.insert(nums[i]);
            }
        }
        return values.size();
    }
};
