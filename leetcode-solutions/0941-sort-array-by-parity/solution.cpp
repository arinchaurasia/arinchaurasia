class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>arr;
        vector<int>odd;

        for(int i: nums){
            if(i%2==0){
                arr.push_back(i);
            }
            else{
                odd.push_back(i);
            }
        }
        for(int i:odd){
            arr.push_back(i);
        }
        return arr;        
    }
};
