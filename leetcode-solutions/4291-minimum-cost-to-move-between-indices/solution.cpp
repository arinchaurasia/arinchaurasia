class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> closest(n);
        closest[0] = 1;

        for (int i = 1; i < n - 1; i++) {
            int leftDiff = nums[i] - nums[i - 1];
            int rightDiff = nums[i + 1] - nums[i];

            if (leftDiff <= rightDiff) {
                closest[i] = i - 1;
            } else {
                closest[i] = i + 1;
            }
        }

        closest[n - 1] = n - 2;

        vector<long long> prefix(n, 0), suffix(n, 0);

        for (int i = 1; i < n; i++) {
            if (closest[i - 1] == i) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1] + (nums[i] - nums[i - 1]);
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (closest[i + 1] == i) {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = suffix[i + 1] + (nums[i + 1] - nums[i]);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            if (l < r) {
                ans.push_back((int)(prefix[r] - prefix[l]));
            } else {
                ans.push_back((int)(suffix[r] - suffix[l]));
            }
        }

        return ans;
    }
};
