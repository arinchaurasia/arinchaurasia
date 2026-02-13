class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false; 

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!parent.count(u)) {
                parent[u] = u;
                rank[u] = 0;
            }
            if (!parent.count(v)) {
                parent[v] = v;
                rank[v] = 0;
            }

            if (!unite(u, v)) {
                return edge;
            }
        }

        return {};
    }
};

