class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int prefix[n];
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            int a = prefix[i] - nums[i];
            int b = sum - prefix[i];
            if (a == b)
                return i;
        }
        return -1;
    }
};
