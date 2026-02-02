class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ancestors) {
        for (int parent : adj[node]) {
            if (!visited[parent]) {
                visited[parent] = 1;
                ancestors.push_back(parent);
                dfs(parent, adj, visited, ancestors);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
        }

        vector<vector<int>> result(n);

        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            dfs(i, adj, visited, result[i]);
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
};

