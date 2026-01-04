class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> n;
            for (int j = 1; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    n.push_back(j);
                    if (j != nums[i] / j)
                        n.push_back(nums[i] / j);
                    if (n.size() > 4)
                        break;
                }
            }
            if (n.size() == 4) {
                for (int k = 0; k < n.size(); k++) {
                    sum += n[k];
                }
            }
        }
        return sum;
    }
};
