#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& b) {
        int m = b.size(), n = b[0].size();

        for (int i = 0; i < m; i++) {
            int pos = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (b[i][j] == '#') {
                    b[i][j] = '.';
                    b[i][pos--] = '#';
                } else if (b[i][j] == '*') {
                    pos = j - 1;
                }
            }
        }

        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = b[i][j];
            }
        }

        return res;
    }
};
