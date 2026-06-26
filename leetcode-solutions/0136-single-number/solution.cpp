class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for (int i = 0;i<nums.size();i++) {
            xor1 = xor1^nums[i];
        }
        return xor1;
    }

    // int singleNumber(vector<int>& nums) {
    //     unordered_map<int,int>mpp;
    //     for(int i = 0;i<nums.size();i++){
    //         mpp[nums[i]]++;
    //     }
    //     for(auto it:mpp){
    //         if(it.second == 1){
    //             return it.first;
    //         }
    //     }
    //     return 0;
    // }


    // int singleNumber(vector<int>& nums) {
    //     for (int i = 0; i < nums.size(); i++) {
    //         int num = nums[i];
    //         int count = 0;
    //         for (int j = 0; j < nums.size(); j++) {
    //             if (nums[j] == num) {
    //                 count++;
    //             }
    //         }
    //         if (count == 1)
    //             return num;
    //     }
    //     return 0;
    // }
};
