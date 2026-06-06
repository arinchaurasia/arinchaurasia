class Solution {
public:
    typedef long long ll;

    struct Node {
        ll cnt, wav;
        Node(ll c = 0, ll w = 0) {
            cnt = c;
            wav = w;
        }
    };

    string s;
    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node solve(int pos, int tight, int st, int a, int b) {

        if (pos == s.size())
            return Node(st ? 1 : 0, 0);

        if (vis[pos][tight][st][a][b])
            return dp[pos][tight][st][a][b];

        vis[pos][tight][st][a][b] = true;

        Node res;

        int lim = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= lim; d++) {

            int nt = (tight && d == lim);

            if (!st) {

                if (d == 0) {
                    Node nxt = solve(pos + 1, nt, 0, 10, 10);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                }
                else {
                    Node nxt = solve(pos + 1, nt, 1, 10, d);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                }
            }
            else {

                int add = 0;

                if (a != 10) {
                    if (a < b && b > d) add++;
                    if (a > b && b < d) add++;
                }

                Node nxt = solve(pos + 1, nt, 1, b, d);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + 1LL * add * nxt.cnt;
            }
        }

        return dp[pos][tight][st][a][b] = res;
    }

    ll calc(ll x) {

        if (x <= 0) return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return solve(0, 1, 0, 10, 10).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};
