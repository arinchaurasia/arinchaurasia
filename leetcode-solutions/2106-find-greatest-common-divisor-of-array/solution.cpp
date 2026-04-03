class Solution {
public:
    int GCD(int a,int b){
        while(a>0 && b>0){
            if(a>b) a = a%b;
            else b= b%a;
        }
        if(a == 0) return b;
        return a;
    }
    int findGCD(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int a = nums[n-1];
        int b = nums[0];

        return GCD(a,b);;
    } 
    


    // int findGCD(vector<int>& nums) {
    //     int n = nums.size();
    //     sort(nums.begin(),nums.end());
    //     int a = nums[n-1];
    //     int b = nums[0];

    //     return gcd(a,b);
        
    // }
};
