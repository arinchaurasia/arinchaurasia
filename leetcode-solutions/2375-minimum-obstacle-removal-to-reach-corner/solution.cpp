class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int cost=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==m-1 && y==n-1) return cost;
            for(auto &d:dir){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int newCost=cost+grid[nx][ny];
                    if(newCost<dist[nx][ny]){
                        dist[nx][ny]=newCost;
                        pq.push({newCost,{nx,ny}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};
