class Solution {
public:
    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += ceil((double)(arr[i]) / (double)(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int th) {
        int n = arr.size();
        if(n>th) return -1;
        int low = 1, high = *max_element(arr.begin(), arr.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sumByD(arr, mid) <= th) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    // int FindMax(vector<int>&arr){
    //     int maxi = INT_MIN;
    //     for(int i = 0;i<arr.size();i++){
    //         maxi = max(maxi,arr[i]);
    //     }
    //     return maxi;
    // }
    // int smallestDivisor(vector<int>& arr, int th) {
    //     int maxi = FindMax(arr);
    //     int n = arr.size();
    //     for(int d = 1;d<=maxi;d++){
    //         int sum = 0;
    //         for(int i = 0;i<n;i++){
    //             sum+=ceil((double)arr[i]/d);
    //         }
    //         if(sum<=th) return d;
    //     }
    //     return -1;
    // }
};
