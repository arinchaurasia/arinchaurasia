class Solution {
public:
    // Dutch National Flag Algorithm
    // void sortColors(vector<int>& a) {
    //     int n = a.size();
    //     int low = 0,mid = 0;
    //     int high = n-1;
    //     while(mid<=high){
    //         if(a[mid] == 0){
    //             swap(a[low],a[mid]);
    //             low++;
    //             mid++;
    //         }
    //         else if(a[mid] == 1){
    //             mid++;
    //         }
    //         else {
    //             swap(a[mid],a[high]);
    //             high--;
    //         }
    //     }
    // }

    void sortColors(vector<int>& a) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)
                cnt0++;
            else if (a[i] == 1)
                cnt1++;
            else
                cnt2++;
        }
        for (int i = 0; i < cnt0; i++) {
            a[i] = 0;
        }
        for (int i = cnt0; i < cnt0 + cnt1; i++) {
            a[i] = 1;
        }
        for (int i = cnt0 + cnt1; i < n; i++) {
            a[i] = 2;
        }
    }
};
