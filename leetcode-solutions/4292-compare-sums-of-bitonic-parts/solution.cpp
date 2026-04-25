class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sumAsc = 0, sumDsc = 0;
        long long peak = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[peak]) {
                peak = i;
            }
        }
        for (int i = 0; i <= peak; i++) {
            sumAsc += nums[i];
        }
        for (int i = peak; i < nums.size(); i++) {
            sumDsc += nums[i];
        }
        if (sumAsc > sumDsc)
            return 0;
        else if (sumAsc < sumDsc)
            return 1;
        else
            return -1;
    }
};
