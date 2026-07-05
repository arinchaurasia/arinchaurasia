class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n + 1, false);
        int ans = INT_MAX;

        function<void(int)> dfs = [&](int node) {
            vis[node] = true;

            for (auto &[next, wt] : adj[node]) {
                ans = min(ans, wt);

                if (!vis[next])
                    dfs(next);
            }
        };

        dfs(1);

        return ans;
    }
};
