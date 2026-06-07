class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int l = max(1,n-k);
        int r = n+k;

        int sum = 0;

        for(int x = l;x<=r;x++){
            if((n&x)==0){
                sum+=x;
            }
        }
        return sum;        
    }
};
