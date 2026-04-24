class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > nums.size() / 3) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
