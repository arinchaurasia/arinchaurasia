class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;
        vector<string> result;

        while (ss >> word) {
            string prefix = "";
            string replaced = word;

            for (char c : word) {
                prefix.push_back(c);  // efficient

                if (st.count(prefix)) {
                    replaced = prefix;
                    break;
                }
            }

            result.push_back(replaced);
        }

        // join words
        string ans = "";
        for (int i = 0; i < result.size(); i++) {
            ans += result[i];
            if (i != result.size() - 1) ans += " ";
        }

        return ans;
    }
};
