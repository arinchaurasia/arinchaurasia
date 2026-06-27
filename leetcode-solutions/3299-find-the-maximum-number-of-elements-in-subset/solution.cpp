#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        for (auto &[x, cnt] : freq) {

            // Special case for 1
            if (x == 1) {
                ans = max(ans, cnt % 2 == 0 ? cnt - 1 : cnt);
                continue;
            }

            long long curr = x;
            int levels = 0;

            while (true) {
                if (!freq.count(curr))
                    break;

                if (freq[curr] == 1) {
                    levels++;
                    break;
                }

                // freq[curr] >= 2

                long long nxt = curr * curr;

                // Prevent overflow / next value absent
                if (curr > 1000000000LL || !freq.count(nxt)) {
                    levels++;
                    break;
                }

                levels++;
                curr = nxt;
            }

            ans = max(ans, 2 * levels - 1);
        }

        return ans;
    }
};
