class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int op = 0;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];

            if (i % 2 == 0) {
                while (!isPrime(val)) {
                    val++;
                    op++;
                }
            } else {
                while (isPrime(val)) {
                    val++;
                    op++;
                }
            }
        }
        return op;
    }
};
