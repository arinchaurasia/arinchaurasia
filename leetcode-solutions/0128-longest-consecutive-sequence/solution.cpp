class Solution {
public:
    // Best O (3n) 
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x += 1;
                    cnt += 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }

    // Better O(Nlog N + N)
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0)
    //         return 0;
    //     sort(nums.begin(), nums.end());

    //     int last_small = INT_MIN;
    //     int cnt = 0, longest = 1;

    //     for (int i = 0; i < n; i++) {
    //         if (nums[i] - 1 == last_small) {
    //             cnt += 1;
    //             last_small = nums[i];
    //         } else if (last_small != nums[i]) {
    //             cnt = 1;
    //             last_small = nums[i];
    //         }

    //         longest = max(longest, cnt);
    //     }
    //     return longest;
    // }

    // Brute Force
    // bool ls(vector<int>& nums, int num) {
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] == num) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // int longestConsecutive(vector<int>& nums) {
    //     int longest = 1, cnt;
    //     int n = nums.size();

    //     if (n == 0)
    //         return 0;

    //     for (int i = 0; i < n; i++) {
    //         int x = nums[i];
    //         cnt = 1;
    //         while (ls(nums, x + 1) == true) {
    //             x = x + 1;
    //             cnt = cnt + 1;
    //         }
    //         longest = max(longest, cnt);
    //     }
    //     return longest;
    // }
};
