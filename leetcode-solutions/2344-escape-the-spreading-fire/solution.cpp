class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Step 1: Calculate when fire reaches each cell
        vector<vector<int>> fireTime(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Add all initial fire positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fireTime[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // BFS to spread fire
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    grid[nx][ny] != 2 && fireTime[nx][ny] == INT_MAX) {
                    fireTime[nx][ny] = fireTime[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        // Step 2: Check if we can reach safehouse with given wait time
        auto canReach = [&](int waitTime) -> bool {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<tuple<int, int, int>> q;
            q.push({0, 0, waitTime});
            visited[0][0] = true;
            
            while (!q.empty()) {
                auto [x, y, time] = q.front();
                q.pop();
                
                // Reached safehouse
                if (x == m - 1 && y == n - 1) {
                    return true;
                }
                
                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                        !visited[nx][ny] && grid[nx][ny] != 2) {
                        int arrivalTime = time + 1;
                        
                        // Check if we can safely reach this cell
                        if (nx == m - 1 && ny == n - 1) {
                            // Safehouse: can arrive at same time as fire
                            if (arrivalTime <= fireTime[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx, ny, arrivalTime});
                            }
                        } else {
                            // Other cells: must arrive before fire
                            if (arrivalTime < fireTime[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx, ny, arrivalTime});
                            }
                        }
                    }
                }
            }
            
            return false;
        };
        
        // Step 3: Binary search on wait time
        if (!canReach(0)) {
            return -1;
        }
        
        if (canReach(1e9)) {
            return 1e9;
        }
        
        int left = 0, right = 1e9;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReach(mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};
