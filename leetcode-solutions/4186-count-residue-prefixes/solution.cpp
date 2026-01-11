class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> result;
        int count =  0;

        for(int i = 0;i<s.size();i++){
            result.insert(s[i]);
            int distinct = result.size();
            int length = (i+1)%3;

            if(distinct == length) count++;           
        }
        return count;
        
    }
};
