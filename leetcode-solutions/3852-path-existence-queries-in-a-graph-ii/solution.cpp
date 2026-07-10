class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                   vector<vector<int>>& queries) {

        vector<pair<int, int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        vector<int> comp(n);

        // position of each original node in sorted order
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // connected components
        int id = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first > maxDiff)
                id++;
            comp[i] = id;
        }

        // next[i] = furthest position reachable in one edge
        vector<int> nxt(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n &&
                   arr[r + 1].first - arr[i].first <= maxDiff)
                r++;
            nxt[i] = r;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int a = pos[u];
            int b = pos[v];

            if (comp[a] != comp[b]) {
                ans.push_back(-1);
                continue;
            }

            if (a > b) swap(a, b);

            int cur = a;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            if (cur < b) {
                cur = nxt[cur];
                steps++;
            }

            ans.push_back(steps);
        }

        return ans;
    }
};
