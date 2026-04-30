class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first;

        int degree = 0;
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            if(first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;  // store first occurrence
            }

            count[nums[i]]++;

            // update degree
            if(count[nums[i]] > degree) {
                degree = count[nums[i]];
                ans = i - first[nums[i]] + 1;
            }
            // same degree → try minimizing length
            else if(count[nums[i]] == degree) {
                ans = min(ans, i - first[nums[i]] + 1);
            }
        }

        return ans;
    }
};
