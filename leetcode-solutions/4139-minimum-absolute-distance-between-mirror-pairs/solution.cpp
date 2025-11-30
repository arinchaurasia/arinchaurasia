class Solution {
public:
    int reverseNum(int x) {
        int r = 0;
        while (x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        vector<int> temp = nums;
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int j = 0; j < temp.size(); j++) {
            int curr = temp[j];
            if (mp.count(curr)) {
                ans = min(ans, j - mp[curr]);
            }
            mp[reverseNum(curr)] = j;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
