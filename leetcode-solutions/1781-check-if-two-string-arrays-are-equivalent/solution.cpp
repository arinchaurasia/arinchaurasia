class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a="";
        string b="";
        for(auto s1:word1){
            a+=s1;
        }
        for(auto s2:word2){
            b+=s2;
        }
        return a==b;
    }
};
