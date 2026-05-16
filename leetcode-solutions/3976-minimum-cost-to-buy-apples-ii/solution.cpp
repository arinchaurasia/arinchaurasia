class Solution {
public:
    vector<long long> dijkstra(int src, int n,
                               vector<vector<pair<int, long long>>>& adj) {

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    vector<int> minCost(int n, vector<int>& prices,
                        vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> emptyAdj(n), appleAdj(n);

        for (auto& r : roads) {
            int u = r[0], v = r[1];
            long long cost = r[2], taxi = r[3];
            emptyAdj[u].push_back({v, cost});
            emptyAdj[v].push_back({u, cost});
            appleAdj[u].push_back({v, cost * taxi});
            appleAdj[v].push_back({u, cost * taxi});
        }

        const long long INF = 1e18;
        vector<vector<long long>> emptyDist(n), appleDist(n);

        for (int i = 0; i < n; i++) {
            emptyDist[i] = dijkstra(i, n, emptyAdj);
            appleDist[i] = dijkstra(i, n, appleAdj);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            long long best = prices[i];
            for (int j = 0; j < n; j++) {
                if (emptyDist[i][j] == INF || appleDist[i][j] == INF)
                    continue;
                long long total = emptyDist[i][j] + prices[j] + appleDist[i][j];
                best = min(best, total);
            }
            ans[i] = (int)best;
        }
        return ans;
    }
};
