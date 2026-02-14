class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (int i = 0; i < words.size(); i++) {
            int total_weight = 0;
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                total_weight += weights[c - 'a'];
            }
            int rem = total_weight % 26;
            char new_char = 'z' - rem;
            result += new_char;
        }
        return result;
    }
};
