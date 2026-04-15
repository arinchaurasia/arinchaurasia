class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        int pref = 0;
        for (int i = 1; i <= n; i++) {
            pref += i;
            if (pref == (sum - pref + i))
                return i;
        }
        return -1;
    }
};
