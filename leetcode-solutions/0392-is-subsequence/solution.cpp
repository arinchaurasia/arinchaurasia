class Solution {
public:
   bool helper(string &s,string &t ,int ind1, int ind2){
        if (ind1==s.length()) {
            return true;
        }
        if(ind2 == t.length()) {
            return false;
        }
        if(s[ind1]==t[ind2]){
            return helper(s,t,ind1+1,ind2+1);
        }
        else{
           return helper(s,t,ind1,ind2+1);
        }
   }
    bool isSubsequence(string s, string t) {
        return helper(s,t,0,0);
    }
};
