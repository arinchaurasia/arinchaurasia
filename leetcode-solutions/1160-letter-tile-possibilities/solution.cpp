class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> visited(tiles.size(), false);
        int ans = 0;
        dfs(tiles, visited, ans);
        return ans;
    }

private:
    void dfs(const string& s, vector<bool>& visited, int& ans) {
        for (int i = 0; i < s.size(); ++i) {
            if (visited[i]) continue;
            if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) continue;
            visited[i] = true;
            ans++;
            dfs(s, visited, ans);
            visited[i] = false;
        }
    }
};

