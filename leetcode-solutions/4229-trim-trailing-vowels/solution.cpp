class Solution {
public:
    string trimTrailingVowels(string s) {
        int i = s.length() - 1;

        while (i >= 0 &&
               (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')) {
            i--;
        }
        s.resize(i + 1);

        return s;
    }
};
