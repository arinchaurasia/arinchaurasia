class Solution {
public:
    bool helper(string &word, int startInd, unordered_set<string> &st, vector<int> &dp){
        if(startInd == word.length()){
            return true;
        }
        if(dp[startInd] != -1) return dp[startInd];
        string curr = "";
        for(int i = startInd; i < word.length(); i++){
            curr.push_back(word[i]);
            // find curr in wordDict
            if(st.count(curr)){
                if(helper(word, i + 1, st, dp)) return dp[startInd] = true;
            }
        }
        return dp[startInd] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length() + 1, -1);
        return helper(s, 0, st, dp);
    }
};
