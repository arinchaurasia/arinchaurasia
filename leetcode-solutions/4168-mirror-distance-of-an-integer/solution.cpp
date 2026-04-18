class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        int N = 0;
        while(n>0){
            int rem = n%10;
            N = 10*N+rem;
            n=n/10;  
        }
        return abs(temp-N);
    }
};
