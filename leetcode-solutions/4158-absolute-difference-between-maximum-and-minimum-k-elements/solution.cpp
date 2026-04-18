class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int sum1 = 0, sum2 = 0;
        
        for (int i = 0; i < k; i++) {
            sum1 += nums[i];
        }
        for (int i = n-1; i >= n-k; i--) {
            sum2 += nums[i];
        }
        return abs(sum1 - sum2);
    }
};
