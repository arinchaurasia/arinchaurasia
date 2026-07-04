class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int preSum = 0,cnt = 0;
        for(int i  =0;i<a.size();i++){
            preSum += a[i];
            int remove = preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]+=1;
        }
        return cnt;
    }
    // int subarraySum(vector<int>& a, int k) {
    //     int n = a.size();
    //     int cnt = 0;
    //     for (int i = 0; i < n; i++) {
    //         int sum = 0;
    //         for (int j = i; j < n; j++) {
    //             sum += a[j];
    //             if (sum == k)
    //                 cnt++;
    //         }
    //     }
    //     return cnt;
    // }


    // int subarraySum(vector<int>& a, int k) {
    //     int n = a.size();
    //     int cnt = 0;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i; j < n; j++) {
    //             int sum = 0;
    //             for (int k = i; k <= j; k++) {
    //                 sum += a[k];
    //             }
    //             if (sum == k)
    //                 cnt++;
    //         }
    //     }
    //     return cnt;
    // }
};
