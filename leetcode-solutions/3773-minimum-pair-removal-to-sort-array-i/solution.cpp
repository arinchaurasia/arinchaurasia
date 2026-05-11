class Solution {
public:

    bool isSorted(vector<int>& nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]){
                return false;
            }
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while(!isSorted(nums)){
            int mini = INT_MAX;
            int index = 0;

            // Find leftmost minimum sum pair
            for(int i = 0; i < nums.size() - 1; i++){
                int sum = nums[i] + nums[i + 1];
                if(sum < mini){
                    mini = sum;
                    index = i;
                }
            }
            // Merge pair
            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);
            operations++;
        }
        return operations;
    }
};
