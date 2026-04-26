class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        visited[x][y] = true;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }
            if (grid[nx][ny] != grid[x][y]) {
                continue;
            }
            if (!visited[nx][ny]) {
                if (dfs(grid, nx, ny, x, y)) {
                    return true;
                }
            } else if (nx != px || ny != py) {
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
