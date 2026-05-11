class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;

        for(int i:nums){
            mp[i]++;
        }
        for(auto &it:mp){
            for(int i = 0;i<it.second;i++){
                ans.push_back(it.first);
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = ans[i];
        }
    }
};
