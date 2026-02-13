class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,vector<vector<int>>& queries) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
        q.push_back({queries[i][0], queries[i][1], queries[i][2], i});
        }

        sort(q.begin(), q.end(),[](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<bool> ans(queries.size());

        int edgeIndex = 0;

        for (auto &query : q) {

            int u = query[0];
            int v = query[1];
            int limit = query[2];
            int idx = query[3];

    while (edgeIndex < edgeList.size() && edgeList[edgeIndex][2] < limit) {
                unite(edgeList[edgeIndex][0],
                      edgeList[edgeIndex][1]);

                edgeIndex++;
            }

            ans[idx] = (find(u) == find(v));
        }

        return ans;
    }
};

