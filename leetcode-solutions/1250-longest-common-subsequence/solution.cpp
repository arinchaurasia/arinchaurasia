class Solution {
public:
    int helper(string &s, string &t, int ind1, int ind2, vector<vector<int>>& dp) {
        // base case
        if (ind1 == s.length() || ind2 == t.length())
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s[ind1] == t[ind2]) {
            return 1 + helper(s, t, ind1 + 1, ind2 + 1, dp);
        } 
        else {
            int skipS = helper(s, t, ind1 + 1, ind2, dp);
            int skipT = helper(s, t, ind1, ind2 + 1, dp);
            return dp[ind1][ind2] = max(skipS, skipT);
        }
    }

    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return helper(s, t, 0, 0, dp);
    }
};

