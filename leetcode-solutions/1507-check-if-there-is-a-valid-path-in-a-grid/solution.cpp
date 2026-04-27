class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // directions: left, right, up, down
        vector<pair<int,int>> dir = {
            {0,-1}, {0,1}, {-1,0}, {1,0}
        };

        // map of street type → allowed directions
        unordered_map<int, vector<int>> mp = {
            {1, {0,1}},
            {2, {2,3}},
            {3, {0,3}},
            {4, {1,3}},
            {5, {0,2}},
            {6, {1,2}}
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n,false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if(x == m-1 && y == n-1) return true;

            for(int d : mp[grid[x][y]]) {
                int nx = x + dir[d].first;
                int ny = y + dir[d].second;

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny])
                    continue;

                // opposite direction
                int opp = (d==0)?1:(d==1)?0:(d==2)?3:2;

                // check if next cell connects back
                for(int nd : mp[grid[nx][ny]]) {
                    if(nd == opp) {
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                        break;
                    }
                }
            }
        }

        return false;
    }
};
