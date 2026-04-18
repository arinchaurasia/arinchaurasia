class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = nums[n-1]-1;
        int j = nums[n-2]-1;
        return i*j;
    }
};
