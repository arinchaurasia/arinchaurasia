class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(0, s, temp, ans);
        return ans;
    }

private:
    void backtrack(int start, string& s, vector<string>& temp, vector<vector<string>>& ans) {
        if (start == (int)s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int end = start; end < (int)s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                temp.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l; --r;
        }
        return true;
    }
};

