class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        
        int ans = 2;
        int a = intervals[0][1] - 1; 
        int b = intervals[0][1];     
        
        for (int i = 1; i < intervals.size(); ++i) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            
            if (s <= a) {
                continue;
            } 
            else if (s <= b) {
                ans += 1;
                a = b;
                b = e;
            } 
            else {
                ans += 2;
                a = e - 1;
                b = e;
            }
        }
        return ans;
    }
};

