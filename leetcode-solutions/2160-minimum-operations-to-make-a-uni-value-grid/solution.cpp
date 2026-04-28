class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        long long count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        int num = arr[0] % x;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % x != num)
                return -1;
        }
        int n = arr.size();
        int med = (n / 2);
        for (int i = 0; i < n; i++) {
            count += abs(arr[i] - arr[med]) / x;
        }
        return count;
    }
};
