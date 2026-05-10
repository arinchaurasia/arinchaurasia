class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        long long sum = 0;

        for (int x : nums) {
            int mini = x;
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    if (st.count(d)) {
                        mini = min(mini, d);
                    }
                    int other = x / d;
                    if (other != d && st.count(other)) {
                        mini = min(mini, other);
                    }
                }
            }
            sum += mini;
        }
        return sum;
    }
};
