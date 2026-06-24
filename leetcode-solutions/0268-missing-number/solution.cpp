class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        int N = nums.size();
        for (int i = 0; i <N; i++) {
            xor1 = xor1 ^ i;
            xor2 = xor2 ^ nums[i]; 
        }
        xor1 = xor1 ^ N;
        return xor1 ^ xor2;
    }



    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int s =0;
    //     int sum = n*(n+1)/2;
    //     for(int i = 0;i<n;i++){
    //         s+=nums[i];
    //     }
    //     return sum-s;
    // }
};
