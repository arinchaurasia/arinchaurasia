class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // Min heap: {cost, x, y}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();
            
            if(x == m-1 && y == n-1) {
                return cost < health;
            }
            
            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if(nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newCost = cost + grid[nx][ny];
                    
                    if(newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }
        
        return false;
    }
};
