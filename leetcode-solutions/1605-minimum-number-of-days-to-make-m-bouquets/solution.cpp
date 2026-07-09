class Solution {
public:
    int FindMin(vector<int>& arr, int n) {
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, arr[i]);
        }
        return mini;
    }

    int FindMax(vector<int>& arr, int n) {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }

    bool possible(vector<int>& arr, int day, int m, int k) {
        int cnt = 0, noOfB = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day)
                cnt++;
            else {
                noOfB += cnt / k;
                cnt = 0;
            }
        }

        noOfB += cnt / k;

        return noOfB >= m;
    }

    int minDays(vector<int>& v, int m, int k) {
        long long n = v.size();

        if (n < 1LL * m * k)
            return -1;

        int low = FindMin(v, n);
        int high = FindMax(v, n);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(v, mid, m, k) == true ) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
