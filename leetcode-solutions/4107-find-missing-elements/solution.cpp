class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[n-1];
        int  j = 0;
        for(int i = mini;i<=maxi;i++){
            if(j<n && nums[j] == i){
                j++;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};
