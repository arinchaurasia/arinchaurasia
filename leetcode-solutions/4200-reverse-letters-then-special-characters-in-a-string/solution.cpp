class Solution {
public:
    string reverseByType(string s) {
        string letter , special_char ;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                letter.push_back(s[i]);
            } else {
                special_char.push_back(s[i]);
            }
        }
            reverse(letter.begin(), letter.end());
            reverse(special_char.begin(), special_char.end());

            int l = 0, sp = 0;

            for (int i = 0; i < s.length(); i++) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] = letter[l];
                    l++;
                } else {
                    s[i] = special_char[sp];
                    sp++;
                }
            }
        return s;
    }
};
