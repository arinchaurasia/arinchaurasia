class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

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

    bool equationsPossible(vector<string>& equations) {
        for (auto& equation : equations) {
            int u = equation[0] -'a';
            int v = equation[3]-'a';
        
            if (!parent.count(u)) {
                parent[u] = u;
                rank[u] = 0;
            }
            if (!parent.count(v)) {
                parent[v] = v;
                rank[v] = 0;
            }
            if (equation[1] == '=') {
                unite(u, v);
            }
        }
            for (auto& equation : equations) {
                int u = equation[0] - 'a';
                int v = equation[3] - 'a';

                if (equation[1] == '!') {
                    if(find(u) == find(v)){
                        return false; 
                    }
                }
            }
        return true;
    }
};

