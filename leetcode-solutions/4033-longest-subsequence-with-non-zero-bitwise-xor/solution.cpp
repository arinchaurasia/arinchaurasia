class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXOR = 0;

        for (int x : nums) {
            totalXOR ^= x;
        }

        if (totalXOR != 0)
            return n;

        for (int x : nums) {
            if (x != 0)
                return n - 1;
        }

        return 0;
    }
};
