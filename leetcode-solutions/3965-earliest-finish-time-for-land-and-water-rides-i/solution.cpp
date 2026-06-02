class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land -> Water
                int finishLand = landStartTime[i] + landDuration[i];
                int finish1 =
                    max(finishLand, waterStartTime[j]) + waterDuration[j];

                // Water -> Land
                int finishWater = waterStartTime[j] + waterDuration[j];
                int finish2 =
                    max(finishWater, landStartTime[i]) + landDuration[i];

                ans = min(ans, min(finish1, finish2));
            }
        }

        return ans;
    }
};
