class Solution {
public:
    // Optimal 
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0  =1;
        // vector<int> row(n, 0); -> matrix[..][0]
        // vector<int> col(m, 0); -> matrix[0][...]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                   //mark the i-th row
                   matrix[i][0] = 0;
                   //mark the j-th col
                    if(j!=0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;    
                }
            }
        }
        for(int i =1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(matrix[i][j] !=0){
                    // check for row & col
                    if(matrix[i][0] == 0|| matrix[0][j] == 0){
                        matrix[i][j]  =0;
                    }
                    
                }
            }
        }
        if(matrix[0][0] == 0) {
            for(int j = 0;j<m;j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0;i<n;i++){
                matrix[i][0] = 0;
            }
        }
        
    }
    // Better 
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     vector<int> row(n, 0);
    //     vector<int> col(m, 0);
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (matrix[i][j] == 0) {
    //                row[i] = 1;
    //                col[j] = 1;
    //             }
    //         }
    //     }
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (row[i] || col[j]) {
    //                matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // Brute
    // void markRow(int i, int m,vector<vector<int>>& matrix) {
    //     for (int j = 0; j < m; j++) {
    //         if (matrix[i][j] != 0) {
    //             matrix[i][j] = -100001;
    //         }
    //     }
    // }
    // void markCol(int j, int n,vector<vector<int>>& matrix) {
    //     for (int i = 0; i < n; i++) {
    //         if (matrix[i][j] != 0) {
    //             matrix[i][j] = -100001;
    //         }
    //     }
    // }

    // void setZeroes(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (matrix[i][j] == 0) {
    //                 markRow(i, m,matrix);
    //                 markCol(j, n,matrix);
    //             }
    //         }
    //     }
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (matrix[i][j] == -100001) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }
};
