class Solution {
public:
    // Brute

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ind = -1;
        int maxCnt = -1;
        for (int i = 0; i < n; i++) {
            int cntRow = 0;
            for (int j = 0; j < m; j++) {
                cntRow += mat[i][j];
            }
            if (cntRow > maxCnt) {
                maxCnt = cntRow;
                ind = i;
            }
        }
        return {ind, maxCnt};
    }
};
