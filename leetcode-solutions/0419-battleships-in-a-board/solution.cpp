class Solution {
    void dfs(int i, int j, vector<vector<char>>& board,
             vector<vector<bool>>& visited) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'X' ||
            visited[i][j] == true) {
            return;
        }
        visited[i][j] = true;
        dfs(i, j + 1, board, visited);
        dfs(i, j - 1, board, visited);
        dfs(i + 1, j, board, visited);
        dfs(i - 1, j, board, visited);
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' && visited[i][j] == false) {
                    dfs(i, j, board, visited);
                    count++;
                }
            }
        }
        return count;
    }
};
