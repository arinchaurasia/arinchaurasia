#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct TrieNode {
        int children[26];
        int best_index;
        
        TrieNode() {
            fill(begin(children), end(children), -1);
            best_index = -1;
        }
    };

    vector<TrieNode> trie;

    void update_best(int node_idx, int word_idx, const vector<string>& wordsContainer) {
        if (trie[node_idx].best_index == -1) {
            trie[node_idx].best_index = word_idx;
        } else {
            int curr_best = trie[node_idx].best_index;
            if (wordsContainer[word_idx].length() < wordsContainer[curr_best].length()) {
                trie[node_idx].best_index = word_idx;
            }
        }
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.push_back(TrieNode());
        
        for (int i = 0; i < wordsContainer.size(); ++i) {
            update_best(0, i, wordsContainer);
            
            int curr = 0;
            for (int j = wordsContainer[i].length() - 1; j >= 0; --j) {
                int char_idx = wordsContainer[i][j] - 'a';
                
                if (trie[curr].children[char_idx] == -1) {
                    trie[curr].children[char_idx] = trie.size();
                    trie.push_back(TrieNode());
                }
                
                curr = trie[curr].children[char_idx];
                update_best(curr, i, wordsContainer);
            }
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& query : wordsQuery) {
            int curr = 0;
            
            for (int j = query.length() - 1; j >= 0; --j) {
                int char_idx = query[j] - 'a';
                
                if (trie[curr].children[char_idx] != -1) {
                    curr = trie[curr].children[char_idx];
                } else {
                    break; 
                }
            }
            ans.push_back(trie[curr].best_index);
        }
        return ans;
    }
};
