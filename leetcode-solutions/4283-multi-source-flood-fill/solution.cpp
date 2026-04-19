class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        vector<vector<int>>midway = sources;

        int dirs [4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        

        for(auto &s:sources){
            int r = s[0],c = s[1],color = s[2];
            grid[r][c] = color;
            dist[r][c] = 0;
            q.push({r,c});
        }
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            for(auto &d :dirs){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr<0 || nc<0 || nr>=n || nc>=m){
                    continue;
                }
                if(dist[nr][nc]>dist[r][c]+1){
                    dist[nr][nc] = dist[r][c]+1;
                    grid[nr][nc] = grid[r][c];
                    q.push({nr,nc});
                }
                else if(dist[nr][nc] == dist[r][c]+1){
                    grid[nr][nc] = max(grid[nr][nc],grid[r][c]);
                }
            }
        }
        return grid;
    }
};
