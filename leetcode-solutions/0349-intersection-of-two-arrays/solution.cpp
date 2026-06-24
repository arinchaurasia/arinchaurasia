class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> ans;

        for (int x : nums2) {
            if (s.count(x))
                ans.insert(x);
        }

        return vector<int>(ans.begin(), ans.end());
    }
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();
    //     int m = nums2.size();
    //     int i = 0;
    //     int j = 0;
    //     vector<int>ans;
    //     sort(nums1.begin(),nums1.end());
    //     sort(nums2.begin(),nums2.end());
    //     while (i < n && j < m) {
    //         if (i > 0 && nums1[i] == nums1[i - 1]) {
    //             i++;
    //             continue;
    //         }
    //         if (j > 0 && nums2[j] == nums2[j - 1]) {
    //             j++;
    //             continue;
    //         }
    //         if (nums1[i] > nums2[j]) {
    //             j++;
    //         } else if (nums1[i] < nums2[j]) {
    //             i++;
    //         } else {
    //             ans.push_back(nums1[i]);
    //             i++;
    //             j++;
    //         }
    //     }
    //     return ans;
    // }
};
