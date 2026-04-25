class Solution {
public:
    int longestPalindrome(string s) {
        int cnt=0;
        vector<int>upper(26,0),lower(26,0);
        for(int i=0;i<s.size();i++){
            int ind=s[i]-'a';
            int ind2=s[i]-'A';
            if(s[i]>='a') lower[ind]++;
            else upper[ind2]++;
        }
        bool odd=0;
        for(int i=0;i<26;i++){
            if(lower[i]%2==0) cnt+=lower[i];
            else {
                cnt+=lower[i]-1;
                odd=1;
            }
            if(upper[i]%2==0) cnt+=upper[i];
            else {
                cnt+=upper[i]-1;
                odd=1;
            }
        }

        return cnt+odd;
    }
};
