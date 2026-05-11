class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int>answer;
        for(int i = 0;i<n;i++){
            int p = nums[i];
                vector<int>ans;
            while(p>0){
                int rem = p%10;
                ans.push_back(rem);
                p /= 10;  
            }
            reverse(ans.begin(),ans.end());
            for(int i:ans){
            answer.push_back(i);
            }
        }    
        return answer;    
    }
};
