class Solution {
public:
    int maxDistinct(string s) {
        set <char> visited;

        for(int i=0;i<s.size();i++){
            visited.insert(s[i]);
        }
        return visited.size();
    }
};
