class Solution {
public:
    vector<vector<int>> g;
    vector<int> bt;

    long long dfs(int u) {
        if (g[u].empty()) {
            return bt[u];
        }

        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;
        for (int v : g[u]) {
            long long childFinish = dfs(v);
            earliest = min(earliest, childFinish);
            latest = max(latest, childFinish);
        }
        long long ownDuration = (latest - earliest) + bt[u];
        return latest + ownDuration;
    }
    long long finishTime(int n, vector<vector<int>>& edges,
                         vector<int>& baseTime) {
        g.assign(n, {});
        bt = baseTime;
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
        }
        return dfs(0);
    }
};
