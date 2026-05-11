class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i : nums) {
            mp[i]++;
        }

        vector<pair<int, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(),
             [](const auto& a, const auto& b) { return a.second < b.second; });
        int n = v.size();
        for (int i = 0; i < k; i++) {
            ans.push_back(v[n - 1 - i].first);
        }
        return ans;
    }
};
