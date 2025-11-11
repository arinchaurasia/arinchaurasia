class Solution {
public:
    void helper(string& word, int startInd, unordered_set<string>& st, vector<string> &ans, string &temp){
        if (startInd == word.length()) {
            temp.pop_back();
            ans.push_back(temp);
            temp.push_back(' ');
            return;
        }
        string curr = "";
        for (int i = startInd; i < word.length(); i++) {
            curr.push_back(word[i]);
            // find curr in wordDict
            if (st.count(curr)) {
                temp += curr;
                temp.push_back(' ');
                helper(word, i + 1, st, ans, temp);
                for(int i = 0; i < 1 + curr.length(); i++){
                    temp.pop_back();
                }
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> ans;
        string temp;
        helper(s, 0, st, ans, temp);
        return ans;
    }
};
