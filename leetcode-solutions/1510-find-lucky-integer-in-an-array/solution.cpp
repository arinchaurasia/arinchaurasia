class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        int count = -1;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        for (auto& it : mp) {
            if (it.first == it.second) {
                count = max(count, it.first);
            }
        }
        return count;
    }
};
