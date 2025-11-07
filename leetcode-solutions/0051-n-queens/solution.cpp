class Solution {
public:
bool isSafe(int row, int col, vector<string> &curr, int n){
        for(int i = 0; i < n; i++){
            if(i == col) continue;
            if(curr[row][i] == 'Q') return false;
        }
        for(int i = 0; i < n; i++){
            if(i == row) continue;
            if(curr[i][col] == 'Q') return false;
        }
        // diagonals
        int r = row - 1;
        int c = col - 1;
        while(r >= 0 && c >= 0){
            if(curr[r][c] == 'Q') return false;
            r--; c--;
        }
        r = row - 1;
        c = col + 1;
        while(r >= 0 && c >= 0){
            if(curr[r][c] == 'Q') return false;
            r--; c++;
        }
        return true;
    }
    void helper(vector<string> &curr, int n, int queens, vector<vector<string>> &ans, int row){
        if(queens == n){
            ans.push_back(curr);
            return;
        }
        if(row == n) return;

        for(int i = 0; i < n; i++){
            if(isSafe(row, i, curr, n)){
                // choose the current option
                curr[row][i] = 'Q';
                helper(curr, n, queens + 1, ans, row+1);
                curr[row][i] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string temp(n, '.');
        vector<string> curr(n, temp);
        helper(curr, n, 0, ans, 0);
        return ans;
    }
};
