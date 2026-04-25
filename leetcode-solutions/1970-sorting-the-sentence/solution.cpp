class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10); 
        string word = "";

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {

                int pos = word.back() - '0'; 
                word.pop_back(); 

                ans[pos] = word; 
                word = ""; 
            } 
            else {
                word += s[i]; 
            }
        }

        string result = "";
        for (int i = 1; i < 10; i++) {
            if (ans[i] != "") {
                if (result != "") result += " ";
                result += ans[i];
            }
        }

        return result;
    }
};
