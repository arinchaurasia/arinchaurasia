class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> v;
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            v.push_back({heights[i], names[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, string>>());

        for (auto& p : v) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
