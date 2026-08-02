class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                prefix[i + 1] = prefix[i] + b;
            } else {
                prefix[i + 1] = prefix[i] - a;
            }
        }
        return mergeSort(prefix, 0, n + 1);
    }

private:
    long long mergeSort(vector<long long>& arr, int left, int right) {
        if (right - left <= 1) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        long long count = 0;
        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid, right);
        int i = left;
        int j = mid;
        while (j < right) {
            while (i < mid && arr[i] < arr[j]) {
                i++;
            }
            count += (mid - i);
            j++;
        }
        vector<long long> temp(right - left);
        i = left;
        j = mid;
        int k = 0;

        while (i < mid && j < right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        while (i < mid) {
            temp[k++] = arr[i++];
        }
        while (j < right) {
            temp[k++] = arr[j++];
        }
        for (int i = 0; i < temp.size(); i++) {
            arr[left + i] = temp[i];
        }
        return count;
    }
};
