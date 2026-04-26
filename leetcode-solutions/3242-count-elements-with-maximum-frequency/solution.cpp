class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0,total = 0;
        unordered_map<int,int>mp;

        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto &p : mp) {
            maxi = max(maxi, p.second);
        }
        for(auto &p:mp){
            if(p.second==maxi){
                total+=p.second;
            }
        }
        return total;       
    }
};
