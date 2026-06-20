class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);
        vector<int> covered(n, 0);
        int cur = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int L = max(0, i - lights[i]);
                int R = min(n - 1, i + lights[i]);

                diff[L]++;
                diff[R + 1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            covered[i] = (cur > 0);
        }
        for (int i = 0; i < n;) {
            if (covered[i]) {
                i++;
                continue;
            }
            ans++;
            int pos = min(n - 1, i + 1);
            int L = max(0, pos - 1);
            int R = min(n - 1, pos + 1);
            for (int j = L; j <= R; j++) {
                covered[j] = 1;
            }
            i = R + 1;
        }
        return ans;
    }
};
