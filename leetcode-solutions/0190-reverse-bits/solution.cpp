class Solution {
public:
    int reverseBits(int n) {
        int num = 0,rem ;
        int i = 0;
        while(i<32){
            rem = n%2;
            num = (num*2)+rem;
            n = n/2;
            i++;
        }
        return num;
    }
};
