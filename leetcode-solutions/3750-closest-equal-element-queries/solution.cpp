#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& v = mp[nums[q]];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            auto it = lower_bound(v.begin(), v.end(), q);

            int best = INT_MAX;

            int nextIdx = (it == v.end() ? v[0] : *it);
            if (nextIdx == q) {
                if (it + 1 != v.end()) nextIdx = *(it + 1);
                else nextIdx = v[0];
            }

            int prevIdx;
            if (it == v.begin()) prevIdx = v.back();
            else {
                prevIdx = *(it - 1);
                if (prevIdx == q) {
                    if (it - 2 >= v.begin()) prevIdx = *(it - 2);
                    else prevIdx = v.back();
                }
            }

            int d1 = abs(nextIdx - q);
            int d2 = abs(prevIdx - q);

            best = min(best, min(d1, n - d1));
            best = min(best, min(d2, n - d2));

            ans.push_back(best);
        }

        return ans;
    }
};
