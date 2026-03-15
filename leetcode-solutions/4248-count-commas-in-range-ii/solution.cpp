class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        for(long long k=1, low =1000;low<=n;k++,low*=1000){
            long long upper = min((long long)n,low*1000-1);
            long long count = upper - low +1;
            res += k* count;
        }
        return res;        
    }
};
