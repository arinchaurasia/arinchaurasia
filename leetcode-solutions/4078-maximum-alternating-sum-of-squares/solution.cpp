class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n);

        // take absolute and square directly
        for(int i = 0; i < n; i++){
            long long x = nums[i];
            arr[i] = x * x;
        }

        sort(arr.begin(), arr.end());

        int start = n / 2;
        long long sum = 0;

        // larger half → positive positions
        for(int i = start; i < n; i++){
            sum += arr[i];
        }

        // smaller half → negative positions
        for(int i = 0; i < start; i++){
            sum -= arr[i];
        }

        return sum;
    }
};
