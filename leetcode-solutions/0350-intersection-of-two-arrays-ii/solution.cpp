class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> result;

        for (int i : nums1) {
            mp[i]++;
        }

        for (int i : nums2) {
            if (mp[i] > 0) {
                result.push_back(i);
                mp[i]--;
            }
        }
        return result;
    }

    // Two Pointer(if arrays are sorted)

    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     sort(nums1.begin(),nums1.end());
    //     sort(nums2.begin(),nums2.end());
    //     vector<int>result;

    //     int i = 0,j = 0;
    //     while(i<nums1.size() && j<nums2.size()){
    //         if(nums1[i]==nums2[j]){
    //             result.push_back(nums1[i]);
    //             i++;
    //             j++;
    //         }
    //         else if(nums1[i]<nums2[j]){
    //             i++;
    //         }
    //         else{
    //             j++;
    //         }
    //     }
    //     return result;
    // }
};
