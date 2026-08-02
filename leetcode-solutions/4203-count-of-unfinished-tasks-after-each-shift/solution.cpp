class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<int> ans;
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + tasks[i];
        }
        long long done = 0;

        for (long long s : shifts) {
            if (done + s >= pre[n]) {
                ans.push_back(0);
                done = 0;
                continue;
            }
            done += s;
            int comp =
                upper_bound(pre.begin(), pre.end(), done) - pre.begin() - 1;
            ans.push_back(n - comp);
        }
        return ans;
    }
};
