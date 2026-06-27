class Solution {
public:
    // Moore's Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int el;
        for(int i = 0;i<n;i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
            
        }
        return el;
        // Not needed below lines if given majority is definitely present.
        // int cnt1 = 0;
        // for(int i = 0;i<nums.size();i++){
        //     if(nums[i] == el){
        //         cnt1++;
        //     }
        // }
        // if(cnt1>n/2) return el;
        // return -1;
    }

    // int majorityElement(vector<int>& nums) {
    //     map<int,int>mpp;

    //     int n = nums.size();
    //     for(int i = 0;i<nums.size();i++){
    //         mpp[nums[i]]++;
    //     }
    //     for(auto it:mpp){
    //         if(it.second>n/2){
    //             return it.first;
    //         }
    //     }
    //     return -1;
    // }
    // int majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++) {
    //         int count = 0;
    //         for (int j = i; j < n; j++) {
    //             if (nums[j] == nums[i]) {
    //                 count++;
    //             }
    //             if (count > n / 2)
    //                 return nums[i];
    //         }
    //     }
    //     return -1;
    // }
};
