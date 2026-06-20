class Solution {
public:
    long long dp[20][11][2];
    long long dfs(int pos, int prev, int st, int tight, string& s, int k) {
        int lim = 9;
        if (pos == s.size()) {
            return st;
        }
        if (!tight && dp[pos][prev + 1][st] != -1) {
            return dp[pos][prev + 1][st];
        }
        if (tight) {
            lim = s[pos] - '0';
        }
        long long ans = 0;
        for (int d = 0; d <= lim; d++) {
            int nt = tight && (d == lim);
            if (!st) {
                if (d == 0) {
                    ans += dfs(pos + 1, -1, 0, nt, s, k);
                } else {
                    ans += dfs(pos + 1, d, 1, nt, s, k);
                }
            } else {
                if (abs(d - prev) <= k) {
                    ans += dfs(pos + 1, d, 1, nt, s, k);
                }
            }
            if (!tight) {
                dp[pos][prev + 1][st] = ans;
            }
        }
        return ans;
    }
    long long solve(long long x, int k) {
        if (x <= 0) {
            return 0;
        }
        string s = to_string(x);
        memset(dp, -1, sizeof(dp));
        return dfs(0, -1, 0, 1, s, k);
    }

    long long goodIntegers(long long l, long long r, int k) {
        return solve(r, k) - solve(l - 1, k);
    }
};
