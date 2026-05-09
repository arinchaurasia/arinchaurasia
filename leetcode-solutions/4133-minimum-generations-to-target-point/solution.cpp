class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>> all;
        for(auto &p : points){
            all.insert(p);
        }
        if(all.count(target))return 0;
         int generation = 0;

        while (true) {
            generation++;
            vector<vector<int>> cur(all.begin(), all.end());
            vector<vector<int>> newPoints;
            int n = cur.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    vector<int> mid = {
                        (cur[i][0] + cur[j][0]) / 2,
                        (cur[i][1] + cur[j][1]) / 2,
                        (cur[i][2] + cur[j][2]) / 2
                    };
                    if (!all.count(mid)) {
                        if (mid == target)
                            return generation;
                        
                        all.insert(mid);
                        newPoints.push_back(mid);
                    }
                }
            }
            if (newPoints.empty())
                return -1;
        }
    }
};
