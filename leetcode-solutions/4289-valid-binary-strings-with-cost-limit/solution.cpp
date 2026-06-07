class Solution {
public:
        vector<string>ans;

        void dfs(int idx,int n,int k,int cost,string &cur){
            if(cost>k){
                return;
            }
            if(idx==n){
                ans.push_back(cur);
                return;
            }
            cur.push_back('0');
            dfs(idx+1,n,k,cost,cur);
            cur.pop_back();

            if(idx == 0 || cur.back() == '0'){
                cur.push_back('1');
                dfs(idx+1,n,k,cost+idx,cur);
                cur.pop_back();
            }
        }
    vector<string> generateValidStrings(int n, int k) {
        string cur = "";
        dfs(0,n,k,0,cur);
        return ans;
    }
};
