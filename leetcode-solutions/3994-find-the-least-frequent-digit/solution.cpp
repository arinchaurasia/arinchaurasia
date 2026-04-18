class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int>freq(10,0);
        while(n>0){
            int rem  = n%10;
            freq[rem]++;
            n=n/10;
        }
        int minFreq = INT_MAX;
        int result = -1;

        for(int i = 0;i<10;i++){
            if(freq[i]>0 && freq[i]<minFreq){
                minFreq = freq[i];
                result = i;
            }
        }
        return result;        
    }
};
