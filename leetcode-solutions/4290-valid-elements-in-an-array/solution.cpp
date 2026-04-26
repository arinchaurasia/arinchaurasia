class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        vector<int> ans;

        leftMax[0] = INT_MIN;
        rightMax[n - 1] = INT_MIN;

        if (n == 1)
            return nums;
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n) {
                ans.push_back(nums[i]);
            } else if (nums[i] > leftMax[i] || nums[i] > rightMax[i]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
