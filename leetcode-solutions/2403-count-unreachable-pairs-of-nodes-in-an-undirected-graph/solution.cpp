class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionNodes(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto edge : edges) {
            unionNodes(edge[0], edge[1]);
        }

        unordered_map<int, long long> componentSize;

        for (int i = 0; i < n; i++) {
            int root = findParent(i);
            componentSize[root]++;
        }

        long long ans = 0;
        long long remaining = n;

        for (int i = 0; i < n; i++) {
            if (componentSize[i] > 0) {
                ans += componentSize[i] * (remaining - componentSize[i]);
                remaining -= componentSize[i];
            }
        }
        return ans;
    }
};

