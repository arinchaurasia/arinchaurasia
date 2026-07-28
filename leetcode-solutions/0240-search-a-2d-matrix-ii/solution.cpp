class Solution {
public:
    // Best
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }

    // Better
    // int binarySearch(vector<int>& matrix, int target) {
    //     int n = matrix.size();
    //     int low = 0, high = n - 1;
    //     while (low <= high) {
    //         int mid = low + (high - low) / 2;
    //         if (matrix[mid] == target) {
    //             return mid;
    //         } else if (target > matrix[mid]) {
    //             low = mid + 1;
    //         } else {
    //             high = mid - 1;
    //         }
    //     }
    //     return -1;
    // }

    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     int ind = -1;
    //     for (int i = 0; i < n; i++) {
    //         ind = binarySearch(matrix[i], target);
    //         if (ind != -1) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // brute
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     for(int i =0;i<n;i++){
    //         for(int j = 0;j<m;j++){
    //             if(matrix[i][j] == target) return true;
    //         }
    //     }
    //     return false;
    // }
};
