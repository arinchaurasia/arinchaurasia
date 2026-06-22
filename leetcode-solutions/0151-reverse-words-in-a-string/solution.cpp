class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            string word = "";

            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            if (!word.empty()) {
                if (ans.empty())
                    ans = word;
                else
                    ans = word + " " + ans;
            }
        }

        return ans;
    }
};
