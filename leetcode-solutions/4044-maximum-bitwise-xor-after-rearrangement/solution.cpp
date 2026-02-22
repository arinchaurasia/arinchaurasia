class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.size();

        int ones = 0;

        for (char c : t) {
            if (c == '1')
                ones++;
        }
        string result = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && ones > 0) {
                result += '1';
                ones--;
            } else if (s[i] == '1' && ones < (n - i)) {
                result += '1';
            } else {
                result += '0';
            }
        }
        return result;
    }
};
