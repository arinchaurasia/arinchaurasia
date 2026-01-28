class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        int pairs = 0, left = 0;
        for (auto& [num, count] : freq) {
            pairs += count / 2;
            left += count % 2;
        }
        return {pairs, left};
    }
};

