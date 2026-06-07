class Solution {
private:
    struct State {
        long long score;
        int cnt;
    };
    State solve(vector<long long>& pre, int n, int l, int r, long long pen) {
        vector<State> dp(n + 1, {0, 0});
        deque<int> dq;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (i >= l) {
                int idx = i - l;
                long long val = dp[idx].score - pre[idx];

                while (!dq.empty()) {
                    int j = dq.back();
                    long long cur = dp[j].score - pre[j];

                    if (cur < val || (cur == val && dp[j].cnt <= dp[idx].cnt)) {
                        dq.pop_back();
                    } else {
                        break;
                    }
                }
                dq.push_back(idx);
            }
            while (!dq.empty() && dq.front() < i - r) {
                dq.pop_front();
            }
            if (!dq.empty()) {
                int j = dq.front();
                long long sc = dp[j].score - pre[j] + pre[i] - pen;
                int c = dp[j].cnt + 1;

                if (sc > dp[i].score || (sc == dp[i].score && c > dp[i].cnt)) {
                    dp[i] = {sc, c};
                }
            }
        }
        return dp[n];
    }

public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        State base = solve(pre, n, l, r, 0);
        if (base.cnt == 0) {
            long long ans = LLONG_MIN;
            deque<int> dq;
            for (int i = l; i <= n; i++) {
                int idx = i - l;
                while (!dq.empty() && pre[dq.back()] >= pre[idx]) {
                    dq.pop_back();
                }
                dq.push_back(idx);
                while (!dq.empty() && dq.front() < i - r) {
                    dq.pop_front();
                }
                ans = max(ans, pre[i] - pre[dq.front()]);
            }
            return ans;
        }
        if (base.cnt <= m) {
            return base.score;
        }
        long long lo = 0, hi = 20000000000LL;
        long long ans = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            State cur = solve(pre, n, l, r, mid);
            if (cur.cnt >= m) {
                ans = cur.score + 1LL * m * mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
