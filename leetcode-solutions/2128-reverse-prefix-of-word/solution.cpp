class Solution {
public:
    string reversePrefix(string word, char ch) {
        int itr = word.find(ch);
        if (itr != string::npos) {
            reverse(word.begin(), word.begin() + itr + 1);
        }
        return word;
    }
};

