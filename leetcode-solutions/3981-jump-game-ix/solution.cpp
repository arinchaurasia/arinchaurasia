#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        vector<int> prefMax(n);
        prefMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        vector<int> ans(n);
        int start = 0;

        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || prefMax[i] <= suffMin[i + 1]) {
                int currentBlockMax = prefMax[i];
                for (int j = start; j <= i; ++j) {
                    ans[j] = currentBlockMax;
                }
                start = i + 1;
            }
        }

        return ans;
    }
};
