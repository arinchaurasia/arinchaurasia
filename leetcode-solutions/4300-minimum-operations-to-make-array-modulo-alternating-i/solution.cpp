class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) {
                    continue;
                }
                int op = 0;
                for (int i = 0; i < n; i++) {
                    int target = (i % 2 == 0) ? x : y;
                    int rem = nums[i] % k;

                    int diff = abs(rem - target);
                    op += min(diff, k - diff);
                }
                ans = min(ans, op);
            }
        }
        return ans;
    }
};
