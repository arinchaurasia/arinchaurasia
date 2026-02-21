class Solution {
public:
    vector<int>parent;
        vector<int>size;

        int find(int x){
            if(parent[x] != x) 
                parent[x] = find(parent[x]);
            return parent[x];    
        }

        void unionr(int x,int y){
            int px = find(x);
            int py = find(y);

            if(px == py) return;

            if(size[px] < size[py]){
                parent[px] = py;
                size[py] += size[px]; 
            }
            else{
                parent[py] = px;
                size[px] += size[py];
            }
        }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }

        for(auto &pair:pairs){
            unionr(pair[0],pair[1]);
        }

        unordered_map<int,vector<int>> groups;
        for(int i = 0;i<n;i++){
            int root = find(i);
            groups[root].push_back(i);
        }

        for (auto &g : groups) {
            vector<int> &indices = g.second;
            string chars = "";

            for (int idx : indices)
                chars += s[idx];

            sort(chars.begin(), chars.end());

            for (int i = 0; i < indices.size(); i++)
                s[indices[i]] = chars[i];
        }
        return s;
    }
};
