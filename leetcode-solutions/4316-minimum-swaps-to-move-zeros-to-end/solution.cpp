class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int op = 0;
        
        for(int x:nums){
            if(x==0){
                zeroCount++;
            }
        }
        for(int i =  n-zeroCount ;i<n;i++){
            if(nums[i]!=0){
                op++;
            }
        }
        return op;
    }
};
