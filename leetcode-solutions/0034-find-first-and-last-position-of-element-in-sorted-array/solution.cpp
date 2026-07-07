class Solution {
public:
//USING BINARY SEARCH DIRECTLY

int firstOccurence(vector<int>& nums, int k){
    int n = nums.size();
    int low = 0,high = n-1;
    int first = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid] == k){
            first = mid;
            high = mid-1;
        }
        else if(nums[mid]<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return first;
}
int lastOccurence(vector<int>& nums, int k){
    int n = nums.size();
    int low = 0,high = n-1;
    int last = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid] == k){
            last = mid;
            low = mid+1;
        }
        else if(nums[mid]<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return last;
}

vector<int> searchRange(vector<int>& nums, int target) {
        int first =firstOccurence(nums,target);
        if(first == -1)return {-1,-1};
        int last = lastOccurence(nums,target) ;
        return {first,last};
    }


//  int lowerBound(vector<int>& arr, int target) {
//         int n = arr.size();
//         int low = 0,high = n-1,ans = n;
//         while(low<=high){
//             int mid = low+(high-low)/2;
//             if(arr[mid]>=target){
//                 ans = mid;
//                 high = mid-1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//     return ans;
//     }
//   int upperBound(vector<int>& arr, int target) {
//         int n = arr.size();
//         int low = 0,high = n-1,ans = n;
//         while(low<=high){
//             int mid = low+(high-low)/2;
//             if(arr[mid]>target){
//                 ans = mid;
//                 high = mid-1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int lb = lowerBound(nums,target) ;
//         if(lb==n || nums[lb]!=target) return {-1,-1};
//         return {lb,upperBound(nums,target)-1};
//     }
};
