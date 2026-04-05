class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int>mpp;
        vector<int>ans;

        for(long long a=1;a*a*a<n;a++){
            long long a3 = a*a*a;
            for(long long b =a;;b++){
                long long b3 = b*b*b;
                long long sum = a3+b3;
                
                if(sum>n){
                    break;
                }
                mpp[sum]++;
            }
        }
        for(auto const&[val,count] :mpp){
            if(count>=2){
                ans.push_back(val);
            }
        }
            
        sort(ans.begin(),ans.end());
        return ans;
    }
};
