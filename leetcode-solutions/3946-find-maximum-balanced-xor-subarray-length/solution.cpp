class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();

        long long p = 0;
        int bal = 0;

        map<pair<long long, int>, int> first;
        first[{0, 0}] = -1;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            p ^= nums[i];
            if (nums[i] % 2 == 0)
                bal++;
            else
                bal--;

            pair<long long, int> key = {p, bal};

            if (first.count(key)) {
                ans = max(ans, i - first[key]);
            } else {
                first[key] = i;
            }
        }
        return ans;
    }
};
