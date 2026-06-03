class Solution {
public:
    long long ans;
    int n, m;

    void solve(vector<int>& s1, vector<int>& d1, vector<int>& s2,
               vector<int>& d2) {

        int sz1 = s1.size();
        int sz2 = s2.size();

        vector<pair<int, int>> rides;
        vector<int> start;
        vector<long long> pre, suf;

        for (int i = 0; i < sz2; i++)
            rides.push_back({s2[i], d2[i]});

        sort(rides.begin(), rides.end());

        start.resize(sz2);
        pre.resize(sz2);
        suf.resize(sz2);

        start[0] = rides[0].first;
        pre[0] = rides[0].second;

        for (int i = 1; i < sz2; i++) {
            start[i] = rides[i].first;
            pre[i] = min(pre[i - 1], (long long)rides[i].second);
        }

        suf[sz2 - 1] = 1LL * rides[sz2 - 1].first + rides[sz2 - 1].second;

        for (int i = sz2 - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], 1LL * rides[i].first + rides[i].second);
        }

        for (int i = 0; i < sz1; i++) {

            long long finishFirst = 1LL * s1[i] + d1[i];

            int idx = upper_bound(start.begin(), start.end(), finishFirst) -
                      start.begin();

            // Second ride already open
            if (idx > 0)
                ans = min(ans, finishFirst + pre[idx - 1]);

            // Need to wait for second ride
            if (idx < sz2)
                ans = min(ans, suf[idx]);
        }
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        ans = 1e18;
        n = landStartTime.size();
        m = waterStartTime.size();

        // Land -> Water
        solve(landStartTime, landDuration, waterStartTime, waterDuration);

        // Water -> Land
        solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return (int)ans;
    }
};
