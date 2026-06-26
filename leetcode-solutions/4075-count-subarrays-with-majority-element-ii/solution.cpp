class Solution {
public:
    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        long long query(int idx) {
            long long res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int offset = n + 2;
        Fenwick ft(2 * n + 5);

        long long ans = 0;
        int pref = 0;

        // Empty prefix
        ft.update(offset, 1);

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            int idx = pref + offset;

            // Count previous prefix sums < current prefix sum
            ans += ft.query(idx - 1);

            ft.update(idx, 1);
        }

        return ans;
    }
};
