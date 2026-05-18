class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();

        if (n == 1)
            return 0;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        vector<bool> visited(n, false);

        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [idx, steps] = q.front();
            q.pop();

            if (idx == n - 1)
                return steps;

            for (int next : mp[arr[idx]]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
            mp[arr[idx]].clear();

            if (idx + 1 < n && !visited[idx + 1]) {
                visited[idx + 1] = true;
                q.push({idx + 1, steps + 1});
            }

            if (idx - 1 >= 0 && !visited[idx - 1]) {
                visited[idx - 1] = true;
                q.push({idx - 1, steps + 1});
            }
        }
        return -1;
    }
};
