class Solution {
public:
    typedef long long ll;
    const ll INF = 4e18;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> graph(n);
        vector<vector<ll>> dist(n, vector<ll>(k + 1, INF));

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>,
                       greater<tuple<ll, int, int>>>
            pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();
            if (cost != dist[u][cnt])
                continue;
            if (u == n - 1)
                return (int)cost;
            for (auto& [v, w] : graph[u]) {
                int newCnt;
                if (labels[v] == labels[u])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;
                if (newCnt > k)
                    continue;
                ll newCost = cost + w;

                if (newCost < dist[v][newCnt]) {
                    dist[v][newCnt] = newCost;
                    pq.push({newCost, v, newCnt});
                }
            }
        }
        return -1;
    }
};
