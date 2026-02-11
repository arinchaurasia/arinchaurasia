class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;
        
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        
        int find(int x) {
            if (parent[x] == x) return x;
            if(parent[x] != x) {
                parent[x] = find(parent[x]); } 
            return parent[x];
        }
        
        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);
            
            if (px == py) return;
            
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    };

    int makeConnected(int V, vector<vector<int>>& edges) {
        if (edges.size() < V - 1) return -1;

        DSU dsu(V);
        int components = V;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                components--;
            }
        }
        return components - 1;
    }
};
