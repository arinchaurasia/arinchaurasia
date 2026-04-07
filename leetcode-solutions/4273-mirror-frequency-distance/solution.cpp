class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char , int >mpp;
        for( auto it : s){
            mpp[it]++;
        }
        for(char ch : s){
            char c = ch;
            if(isdigit(c)){
                int value = c -'0'; // '1'- '0' = 1
                char mirror = '0' + '9' - c;
                if( mpp[mirror] != 0 ){              // mpp.find(mirror) != mpp.end();
                    int mini = min(mpp[c] , mpp[mirror]);
                    // ans = ans + mini;
                    mpp[c] = mpp[c] - mini;
                    mpp[mirror] = mpp[mirror] - mini; //z = 0 ,  a a a a a z z = 
                }
                else{
                    ans = ans + mpp[c];
                    //asdgracfgadga
                    mpp[c] = 0;    
                }
// 5 2 -> 3 0 -> ans  = 3 
            }
            else{
                char mirror = 'a' + 'z' - c;  // 97 + 132 - 97 = 132 ;
                if( mpp[mirror] != 0 ){              // mpp.find(mirror) != mpp.end();
                    int mini = min(mpp[c] , mpp[mirror]);
                    // ans = ans + mini;
                    mpp[c] = mpp[c] - mini;
                    mpp[mirror] = mpp[mirror] - mini; //z = 0
                }
                else{
                    ans = ans + mpp[c];
                    mpp[c] = 0;    
                }
            }
        }
        return ans;
    } 
};
