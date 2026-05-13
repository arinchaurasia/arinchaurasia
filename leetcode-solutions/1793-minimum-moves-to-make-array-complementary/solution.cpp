class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int x = min(a, b);
            int y = max(a, b);
            int pairSum = a + b;
            
            diff[2] += 2;

          
            diff[x + 1] -= 1;
            diff[y + limit + 1] += 1;

            diff[pairSum] -= 1;
            diff[pairSum + 1] += 1;
        }

        int ans = INT_MAX;
        int currMoves = 0;

        for (int sum = 2; sum <= 2 * limit; sum++) {
            currMoves += diff[sum];
            ans = min(ans, currMoves);
        }
        return ans;
    }
};
