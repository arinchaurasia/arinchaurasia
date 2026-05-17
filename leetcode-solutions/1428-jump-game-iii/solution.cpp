class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            
            if (arr[idx] == 0)
                return true;

            int forward = idx + arr[idx];
            int backward = idx - arr[idx];

            if (forward < n && !visited[forward]) {
                visited[forward] = true;
                q.push(forward);
            }

            if (backward >= 0 && !visited[backward]) {
                visited[backward] = true;
                q.push(backward);
            }
        }
        return false;
    }
};
