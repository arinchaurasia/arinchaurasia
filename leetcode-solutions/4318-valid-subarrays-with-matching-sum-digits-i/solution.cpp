class Solution {
public:
    int firstDigit(long long num) {
        while (num >= 10) {
            num /= 10;
        }
        return (int)num;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        long long ans = 0;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                long long sum = prefix[r + 1] - prefix[l];
                if (sum % 10 == x && firstDigit(sum) == x) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
