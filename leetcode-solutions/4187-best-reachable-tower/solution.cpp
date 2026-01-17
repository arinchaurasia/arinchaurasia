class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        
        int bestQuality = -1;
        int bestX = -1;
        int bestY = -1;

        for (int i = 0; i < towers.size(); i++) {
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];

            if (abs(x - center[0]) + abs(y - center[1]) > radius) {
                continue;
            }
            if (q > bestQuality || (q == bestQuality && (x < bestX || (x == bestX && y < bestY)))) {
                bestQuality = q;
                bestX = x;
                bestY = y;
            }
        }
        if (bestQuality == -1) {
            return vector<int>{-1, -1};
        }
    return vector<int>{bestX, bestY};
    }
};
