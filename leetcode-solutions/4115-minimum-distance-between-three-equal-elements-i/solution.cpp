class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
            auto &v = mp[nums[i]];

            if (v.size() >= 3) {
                int n = v.size();
                int dist = 2 * (v[n - 1] - v[n - 3]);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
