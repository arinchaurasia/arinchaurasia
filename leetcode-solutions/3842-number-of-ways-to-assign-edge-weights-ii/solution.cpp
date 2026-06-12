class Solution {
public:
    static const int MOD = 1e9 + 7;
    int LOG;

    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;
    vector<vector<int>> adj;

    void dfs(int node, int parent) {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int nei : adj[node]) {
            if (nei == parent)
                continue;

            depth[nei] = depth[node] + 1;
            dfs(nei, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j))
                u = up[u][j];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        LOG = 17;
        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n + 1, {});
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, 1));

        dfs(1, 1);

        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            int L = lca(u, v);

            int len = depth[u] + depth[v] - 2 * depth[L];

            if (len == 0)
                ans.push_back(0);
            else
                ans.push_back((int)pow2[len - 1]);
        }

        return ans;
    }
};
