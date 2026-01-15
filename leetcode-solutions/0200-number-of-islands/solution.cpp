class Solution {
public:
    void bfs(vector<vector<char>>& grid, int row, int col,vector<vector<bool>>& isVis) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        isVis[row][col] = true;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1'
                 && !isVis[nr][nc]) {
                    isVis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> isVis(n, vector<bool>(m, false));
        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && isVis[i][j] == false) {
                    islands++;
                    bfs(grid, i, j, isVis);
                }
            }
        }
        return islands;
    }
};
