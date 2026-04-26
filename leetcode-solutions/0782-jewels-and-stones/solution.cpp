class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        
        for(char c : jewels) {
            s.insert(c);
        }
        
        int count = 0;
        
        for(char c : stones) {
            if(s.count(c)) {
                count++;
            }
        }
        
        return count;
    }
};
