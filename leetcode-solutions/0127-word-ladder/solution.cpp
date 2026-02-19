class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> WordSet(wordList.begin(), wordList.end());
        if (!WordSet.count(endWord)) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i <size; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return level;

                for (int j = 0; j < word.length(); j++) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c;
                        if (WordSet.count(word)) {
                            q.push(word);
                            WordSet.erase(word);
                        }
                    }
                    word[j] = original;
                }
            }
            level++;
        }
        return 0;
    }
};
