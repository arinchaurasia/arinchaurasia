class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int sum =0;
        for(int i=0; i<n ; i++){
            sum = sum + abs(nums[0] - nums[i]);
        }
        ans.push_back(sum);
        for(int i=1; i<n; i++){
            int diff =nums[i] - nums[i-1];
            sum = sum + (2*i - n)*diff;
            ans.push_back(sum);
        }
        return ans;
    }
};
