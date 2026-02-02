class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    vector<int> quiet;

    int dfs(int node) {
        if (ans[node] != -1)
            return ans[node];

        ans[node] = node;

        for (int parent : adj[node]) {
            int curr = dfs(parent);
            if (quiet[curr] < quiet[ans[node]]) {
                ans[node] = curr;
            }
        }
        return ans[node];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet_) {
        quiet = quiet_;
        int n = quiet.size();
        adj.resize(n);
        ans.assign(n, -1);

         for(int i = 0;i<richer.size();i++)
        {
            int u = richer[i][0];
            int v = richer[i][1];
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            dfs(i);
        }

        return ans;
    }
};

