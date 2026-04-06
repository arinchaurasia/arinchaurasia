class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        if (n < 3)
            return false;

        while (left + 1 < n && arr[left] < arr[left + 1]) {
            left++;
        }
        while (right - 1 >= 0 && arr[right - 1] > arr[right]) {
            right--;
        }
        return (left > 0 && right < n - 1 && left == right);

        

        // Brute Force

        // bool validMountainArray(vector<int>& arr) {
        //     int n = arr.size();
        //     if (n < 3) return false;

        //     int temp = 0, i;
        //     int flag1 = 0, flag2 = 0;

        //     for (i = 0; i < n - 1; i++) {
        //         if (arr[i] < arr[i + 1]) {
        //             flag1++;
        //         } else {
        //             temp = i;
        //             break;
        //         }
        //     }

        //     if (temp == 0 || temp == n - 1) return false;

        //     for (i = temp; i < n - 1; i++) {
        //         if (arr[i] > arr[i + 1]) {
        //             flag2++;
        //         } else {
        //             break;
        //         }
        //     }

        //     if (i != n - 1) return false;

        //     return (flag1 > 0 && flag2 > 0);
    }
};
