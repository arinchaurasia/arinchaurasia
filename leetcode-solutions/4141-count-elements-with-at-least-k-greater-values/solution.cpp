class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0) return n;

        vector<int>arr = nums;
        sort(arr.begin(),arr.end());
        int limit = arr[n-k];
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<limit) {
                count++;
            }
        }
        return count;
    }
};
