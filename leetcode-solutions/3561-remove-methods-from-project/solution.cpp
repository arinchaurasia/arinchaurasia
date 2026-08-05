class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);
        vector<int> suspicious(n, 0);
        vector<int> ans;

        for (auto& it : invocations) {
            adj[it[0]].push_back(it[1]);
        }
        queue<int> q;
        q.push(k);
        suspicious[k] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int next : adj[node]) {
                if (!suspicious[next]) {
                    suspicious[next] = 1;
                    q.push(next);
                }
            }
        }
        for (auto& it : invocations) {
            int from = it[0];
            int to = it[1];

            if (!suspicious[from] && suspicious[to]) {
                vector<int> ans;

                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
