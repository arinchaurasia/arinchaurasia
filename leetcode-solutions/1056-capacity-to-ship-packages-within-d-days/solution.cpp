class Solution {
public:
    int FindMax(vector<int>& weights, int n) {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }
    int TotalSum(vector<int>& weights, int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += weights[i];
        }
        return sum;
    }
    int DaysReq(vector<int>& wt, int mid) {
        int day = 1, load = 0;
        for (int i = 0; i < wt.size(); i++) {
            if (load + wt[i] > mid) {
                day = day + 1;
                load = wt[i];
            } else {
                load += wt[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = FindMax(weights, n);
        int high = TotalSum(weights, n);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int NoOfDays = DaysReq(weights, mid);
            if (NoOfDays <= days) {
                high = mid - 1;
            } else {
                low= mid + 1;
            }
        }
        return low;
    }
};
