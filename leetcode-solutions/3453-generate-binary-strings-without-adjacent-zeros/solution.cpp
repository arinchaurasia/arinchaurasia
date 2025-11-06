class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string path;
        helper(n, 0, '#', path, res);
        return res;
    }

private:
    void helper(int n, int index, char prev, string &path, vector<string> &res) {

        if (index == n) {
            res.push_back(path);
            return;
        }

        path.push_back('1');
        helper(n, index + 1, '1', path, res);
        path.pop_back();

        if (prev != '0') {
            path.push_back('0');
            helper(n, index + 1, '0', path, res);
            path.pop_back();
        }
    }
};

