class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
            greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node])
                continue;

            for (int j = 0; j < adj[node].size(); j++) {
                int adjNode = adj[node][j].first;
                int adjNodewt = adj[node][j].second;

                long long newDist = dis + adjNodewt;

                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    pq.push({newDist, adjNode});
                } else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
