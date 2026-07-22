class Solution {
public:
long long cntStd(vector<int>&arr,long long pages){
        long long Stu = 1, pagesStudent = 0;
        for(int i = 0;i<arr.size();i++){
            if(pagesStudent + arr[i]<=pages){
                pagesStudent = pagesStudent + arr[i];
            }
            else{
                Stu++;
                pagesStudent = arr[i];
            }
        }
        return Stu;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > arr.size()) return -1;
        long long low = *max_element(arr.begin(),arr.end());
        long long high = accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
        long long mid = low + (high - low) / 2;
        long long students = cntStd(arr,mid);
            if(students>k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};
