class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int minimum = INT_MAX;

        sort(arr.begin(), arr.end());

        vector<vector<int>> result;

        for (int i = 1; i < n; i++) {
            minimum = min(minimum, arr[i] - arr[i - 1]);
        }

        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == minimum) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};
