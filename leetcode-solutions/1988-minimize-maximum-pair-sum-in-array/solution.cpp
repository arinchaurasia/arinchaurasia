class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int left = 0, maximum = INT_MIN;
        int right = nums.size() - 1;
        sort(nums.begin(), nums.end());

        while (left < right) {
            maximum = max(maximum, nums[left] + nums[right]);
            left++;
            right--;
        }
        return maximum;
    }
};
