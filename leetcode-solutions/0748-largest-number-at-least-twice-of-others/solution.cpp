class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();

        int maxVal = -1, secondMax = -1, index = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxVal) {
                secondMax = maxVal;
                maxVal = nums[i];
                index = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }

        if (maxVal >= 2 * secondMax) {
            return index;
        }

        return -1;
    }
};
