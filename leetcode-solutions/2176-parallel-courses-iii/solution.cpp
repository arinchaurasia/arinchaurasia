class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        // Create a adjacency list
        vector<int>adj[n];
        vector<int>InDeg(n,0);

        for(int i = 0;i<relations.size();i++)
        {
            // Convert them into 0-based indexing
            int u = relations[i][0]-1;
            int v = relations[i][1]-1;
            adj[u].push_back(v);
            InDeg[v]++;
        }

        queue<int>q;
        for(int i = 0;i<n;i++)
        {
            if(!InDeg[i]){
                q.push(i);
            }
        }
        // Maximum time to complete previous course
        vector<int>CourseTime(n,0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j = 0;j<adj[node].size();j++)
            {
                InDeg[adj[node][j]]--;
                if(!InDeg[adj[node][j]])
                {
                    q.push(adj[node][j]);

                    }
// Maximum time to complete previous course + Present course time
                CourseTime[adj[node][j]] = max(CourseTime[adj[node][j]] ,CourseTime[node] + time[node]);
            }
        }    

        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,CourseTime[i]+time[i]);
        }    
        return ans;
    }
};
