class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
       string s = "";
        int count = 0;
        for(int i: nums){
            s += to_string(i);
        }
        int n = s.length();
        for(int i =0;i<n;i++){
            if(s[i] == digit+'0') count++;
        }
        return count;
    }
};
