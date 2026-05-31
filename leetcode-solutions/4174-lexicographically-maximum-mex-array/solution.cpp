class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        int current_mex = 0;
        vector<int> suffix_mex(n);
        vector<int> result;
        vector<int> to_clear;

        vector<bool> seen(n + 2, false);
        vector<bool> local_seen(n + 2, false);

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] <= n) {
                seen[nums[i]] = true;
            }
            while (seen[current_mex]) {
                current_mex++;
            }
            suffix_mex[i] = current_mex;
        }
        int start = 0;

        while (start < n) {
            int target_mex = suffix_mex[start];
            int local_mex = 0;
            for (int i = start; i < n; i++) {
                if (nums[i] <= n) {
                    local_seen[nums[i]] = true;
                    to_clear.push_back(nums[i]);
                }
                while (local_seen[local_mex]) {
                    local_mex++;
                }
                if (local_mex == target_mex) {
                    result.push_back(target_mex);
                
                for (int val : to_clear) {
                    local_seen[val] = false;
                }
                to_clear.clear();
                start = i + 1;
                break;
            }
        }
    }
    return result;
}
};
