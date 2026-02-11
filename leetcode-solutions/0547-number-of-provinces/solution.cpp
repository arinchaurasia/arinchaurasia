class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]);
        return parent[x];
    }
    
    void unionSet(vector<int>& parent, vector<int>& rankArr, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        
        if (px == py) return;
        
        if (rankArr[px] < rankArr[py])
            parent[px] = py;
        else if (rankArr[py] < rankArr[px])
            parent[py] = px;
        else {
            parent[py] = px;
            rankArr[px]++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> parent(n);
        vector<int> rankArr(n, 0);
        
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    unionSet(parent, rankArr, i, j);
                }
            }
        }
        
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (find(parent, i) == i)
                provinces++;
        }
        
        return provinces;
    }
};

