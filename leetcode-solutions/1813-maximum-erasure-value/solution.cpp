class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0,ans=0;
        unordered_map<int,int> mp;
        int i=0,j=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            sum+=nums[j];
            while(mp[nums[j]]>1){
                mp[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            ans= max(ans,sum);
            j++;
        }
        return ans;
        
    }
};
