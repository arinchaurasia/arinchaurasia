class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int from=flights[i][0];
            int to=flights[i][1];
            int price=flights[i][2];
            adj[from].push_back({to,price});
        }
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int node=q.front().second.first;
            int cost=q.front().second.second;
            int stops=q.front().first;
            q.pop();
            if(stops>k){
                continue;
            }
            for(int i=0;i<adj[node].size();i++){
                int neigh=adj[node][i].first;
                int p=adj[node][i].second;
                if(cost+p<dis[neigh]){
                    dis[neigh]=cost+p;
                    q.push({stops+1,{neigh,dis[neigh]}});
                }
            }
        }
        if(dis[dst]==INT_MAX){
            return -1;
        }
        return dis[dst];
    }
};
