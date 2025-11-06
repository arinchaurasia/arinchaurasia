#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        static const unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res;
        string path;
        path.reserve(digits.size());

        dfs(digits, 0, phoneMap, path, res);
        return res;
    }

private:
    void dfs(const string& digits, int idx,
             const unordered_map<char, string>& phoneMap,
             string& path, vector<string>& res) {
        
        if (idx == (int)digits.size()) {
            res.push_back(path);
            return;
        }

        const string& letters = phoneMap.at(digits[idx]);
        for (char c : letters) {
            path.push_back(c);
            dfs(digits, idx + 1, phoneMap, path, res);
            path.pop_back();
        }
    }
};

