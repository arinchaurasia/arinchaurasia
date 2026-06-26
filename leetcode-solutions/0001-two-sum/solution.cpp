class Solution {
public:
// vector<int> twoSum(vector<int>& nums, int target) {
//     map<int, int> mpp;
//     int n = nums.size();
//     for (int i = 0; i < n; i++) {
//         int num = nums[i];
//         int moreNeeded = target - num;
//         if (mpp.find(moreNeeded) != mpp.end()) {
//             return {mpp[moreNeeded], i};
//         }
//         mpp[num] = i;
//     }
//     return {-1, -1};
// }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int sum = nums[i]+nums[j];
                if(sum == target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }

    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<pair<int, int>> v;

    //     for (int i = 0; i < nums.size(); i++)
    //         v.push_back({nums[i], i});

    //     sort(v.begin(), v.end());

    //     int left = 0;
    //     int right = v.size() - 1;

    //     while (left < right) {
    //         int sum = v[left].first + v[right].first;

    //         if (sum == target)
    //             return {v[left].second, v[right].second};
    //         else if (sum < target)
    //             left++;
    //         else
    //             right--;
    //     }
    //     return {};
    // }
};
