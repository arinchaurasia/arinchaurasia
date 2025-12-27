class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        for (char s : address) {
            if (s == '.') {
                result += "[.]";
            } else {
                result += s;
            }
        }
        return result;
    }
};
