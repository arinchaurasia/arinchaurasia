class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        int curr = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[curr] = nums[left] * nums[left];
                left++;
            } else {
                result[curr] = nums[right] * nums[right];
                right--;
            }
            curr--;
        }
        return result;
    }
};
