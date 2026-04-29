#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n <= 1) {
            return 0;
        }

        vector<vector<long long>> prefix(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                prefix[j][i + 1] = prefix[j][i] + grid[i][j];
            }
        }

        vector<long long> prev_pick(n + 1, 0);
        vector<long long> prev_skip(n + 1, 0);

        for (int j = 1; j < n; ++j) {
            vector<long long> curr_pick(n + 1, 0);
            vector<long long> curr_skip(n + 1, 0);

            for (int curr = 0; curr <= n; ++curr) {
                for (int prev = 0; prev <= n; ++prev) {
                    if (curr > prev) {
                        long long score =
                            prefix[j - 1][curr] - prefix[j - 1][prev];
                        curr_pick[curr] =
                            max(curr_pick[curr], prev_skip[prev] + score);
                        curr_skip[curr] =
                            max(curr_skip[curr], prev_skip[prev] + score);
                    } else {
                        long long score = prefix[j][prev] - prefix[j][curr];
                        curr_pick[curr] =
                            max(curr_pick[curr], prev_pick[prev] + score);
                        curr_skip[curr] = max(curr_skip[curr], prev_pick[prev]);
                    }
                }
            }
            prev_pick = curr_pick;
            prev_skip = curr_skip;
        }

        return *max_element(prev_pick.begin(), prev_pick.end());
    }
};
