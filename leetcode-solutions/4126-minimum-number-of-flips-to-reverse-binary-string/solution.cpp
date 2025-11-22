class Solution {
public:
    int minimumFlips(int n) {
        string s = "";

        while (n > 0) {
            s.push_back((n & 1) + '0');  
            n >>= 1;
        }
        reverse(s.begin(), s.end());     

        int i = 0;
        int j = (int)s.size() - 1;
        int mismatchedPairs = 0;

        while (i < j) {
            if (s[i] != s[j]) 
                mismatchedPairs++;
            i++;
            j--;
        }

        return mismatchedPairs * 2;      
    }
};

