class Solution {
public:
    bool isLetter(char c) { 
        return c >= 'a' && c <= 'z'; 
        }

    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {

        string s = "";

        for (string& part : chunks) {
            s += part;
        }

        unordered_map<string, int> freq;
        string currentWord = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isLetter(c)) {
                currentWord += c;
            } else if (c == '-' && !currentWord.empty() && i + 1 < n &&
                       isLetter(s[i + 1])) {

                currentWord += '-';
            } else {
                if (!currentWord.empty()) {

                    if (currentWord.back() == '-') {
                        currentWord.pop_back();
                    }

                    if (!currentWord.empty()) {
                        freq[currentWord]++;
                    }

                    currentWord = "";
                }
            }
        }

        if (!currentWord.empty()) {

            if (currentWord.back() == '-') {
                currentWord.pop_back();
            }

            if (!currentWord.empty()) {
                freq[currentWord]++;
            }
        }

        vector<int> answer;

        for (string& query : queries) {
            answer.push_back(freq[query]);
        }

        return answer;
    }
};
