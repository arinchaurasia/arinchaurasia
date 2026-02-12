class Solution {
public:
    bool isBalanced(vector<int>& freq) {
        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (count == 0) {
                    count = freq[i];
                } else if (freq[i] != count) {
                    return false;
                }
            }
        }

        return true;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if (isBalanced(freq)) {
                    int length = j - i + 1;
                    maxLength = max(maxLength, length);
                }
            }
        }

        return maxLength;
    }
};

