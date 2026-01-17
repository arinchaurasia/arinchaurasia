class Solution {
public:
    void bfs(int row, int col, vector<vector<bool>>& visited,
             vector<vector<char>>& board,int n, int m) {

        queue<pair<int,int>> q;
        q.push({row, col});
        visited[row][col] = true;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    board[nr][nc] == 'O' && !visited[nr][nc]) {

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !visited[i][0])
                bfs(i, 0, visited, board, n, m);
            if (board[i][m-1] == 'O' && !visited[i][m-1])
                bfs(i, m-1, visited, board, n, m);
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !visited[0][j])
                bfs(0, j, visited, board, n, m);
            if (board[n-1][j] == 'O' && !visited[n-1][j])
                bfs(n-1, j, visited, board, n, m);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

