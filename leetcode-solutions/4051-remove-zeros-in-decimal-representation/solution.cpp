class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string res = "";

        for(char c : s) {
            if(c != '0') {
                res += c;
            }
        }

        // if all digits were zero
        if(res.empty()) return 0;

        return stoll(res);
    }


    // long long removeZeros(long long n) {
    //     string s="";
    //     while(n>0){
    //         int r = n%10;
    //         n= n/10;
    //         if(r==0) continue;
    //         s+=to_string(r);
    //     }
    //     reverse(s.begin(),s.end());
    //     return stoll(s);
    // }
};
