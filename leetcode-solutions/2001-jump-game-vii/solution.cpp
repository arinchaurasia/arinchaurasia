class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        int farthest = 0;

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;


        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0' && !visited[j]) {
                    if (j == n - 1)
                        return true;

                    visited[j] = true;
                    q.push(j);
                }
            }

            farthest = max(farthest, end);
        }
        return n == 1;
    }
};
