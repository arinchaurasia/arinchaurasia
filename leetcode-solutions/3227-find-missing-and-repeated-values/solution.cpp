class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        vector<int> ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                arr.push_back(grid[i][j]);
            }
        }
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            if(mp[arr[i]]>=2) ans.push_back(arr[i]);
        }
        unordered_set<int> st(arr.begin(),arr.end());
        int add=0;
        for(auto x:st){
            add+=x;
        }
        int sum=n*(n+1)/2;
        int num=sum-add;
        ans.push_back(num);
        return ans;


        
    }
};
