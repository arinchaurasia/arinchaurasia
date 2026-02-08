class Solution {
  public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        // Adjacency list create karo
        vector<int>adj[N];
        vector<int>InDeg(N,0);
        
        for(int i = 0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            InDeg[u] ++;
        }
        
        // Kahn's Algorithm
        // Indegree find krna
        queue<int>q;
        for(int i = 0;i<N;i++){
            if(InDeg[i] == 0){
                q.push(i);
            }
        }
        int count = 0; // Size of Topo Sort
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(int j = 0;j<adj[node].size();j++)
            {
                InDeg[adj[node][j]]--;
                if(!InDeg[adj[node][j]])
                {
                    q.push(adj[node][j]);   
                }
            }
        }
        return count == N;
        // Directed Acyclic Graph
        // Size == N (I can complete all task)
    }
};
