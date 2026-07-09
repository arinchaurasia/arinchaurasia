class Solution {
public:
    int findMax(vector<int>&v){
        int n = v.size();
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }
    long long calculateTotalHours(vector<int> &v,int h){
        long long totalHour = 0;
        for(int i = 0;i<v.size();i++){
            totalHour += ceil((double)v[i]/(double)h);
        }
        return totalHour;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int low=  1,high = findMax(v);
        int ans = high;
        while(low<=high){
            int mid = low+(high-low)/2;
            long long totalH = calculateTotalHours(v,mid);
            if(totalH<=h) {
                ans = mid;
                high = mid-1;
            } 
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
