class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long str1 = 0,den = 0,strength,den2 = 0;
        long long maxstrength = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<n;j++){
                den = gcd(nums[i],nums[j]);
                den2 = den*den;
                strength = (1LL*nums[i]*nums[j]/den2);
                maxstrength = max(strength,maxstrength);
            }
        }
        return maxstrength;
    }
};
