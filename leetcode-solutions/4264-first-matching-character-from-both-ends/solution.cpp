class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.length();
        int i = 0;
        
        while(i<=n/2){
            if(s[i] == s[n-i-1]){
                return i;
            }
            else{
                i++;
            }
            
        }
        return -1;
    }
};
