class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        // dp ending at value i
        vector<int> up(m), down(m);

        // length = 2
        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {

            vector<int> pref(m), suff(m);

            pref[0] = down[0];
            for (int i = 1; i < m; i++) {
                int x = pref[i - 1] + down[i];
                if (x >= MOD) x -= MOD;
                pref[i] = x;
            }

            suff[m - 1] = up[m - 1];
            for (int i = m - 2; i >= 0; i--) {
                int x = suff[i + 1] + up[i];
                if (x >= MOD) x -= MOD;
                suff[i] = x;
            }

            vector<int> nextUp(m, 0), nextDown(m, 0);

            for (int i = 0; i < m; i++) {
                if (i > 0)
                    nextUp[i] = pref[i - 1];
                if (i + 1 < m)
                    nextDown[i] = suff[i + 1];
            }

            up.swap(nextUp);
            down.swap(nextDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans += up[i];
            ans += down[i];
            ans %= MOD;
        }

        return (int)ans;
    }
};
