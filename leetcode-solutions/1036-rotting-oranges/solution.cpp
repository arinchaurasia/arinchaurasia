class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int n, m;
    
    bool isValid(int i, int j) {
        if (i >= 0 && i < n && j >= 0 && j < m) {
            return true;
        } else {
            return false;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        int timer = 0;

        while (!q.empty()) {
            int curr = q.size();
            timer++;
            while (curr--) {
                int n_row = q.front().first;
                int n_col = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    if (isValid(n_row + row[k], n_col + col[k]) && grid[n_row + row[k]][n_col + col[k]] == 1) {
                        grid[n_row + row[k]][n_col + col[k]] = 2;
                        q.push({n_row + row[k], n_col + col[k]});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return timer - 1;
    }
};
