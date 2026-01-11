class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            unordered_set<int> result;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                result.insert(nums[j]);

                if (result.count(sum))
                    count++;
            }
        }
        return count;
    }
};
