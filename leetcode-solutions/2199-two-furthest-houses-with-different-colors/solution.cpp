class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int ans = 0;
        int i = 0;
        int j = n - 1;
        
        while (colors[0] == colors[j]) {
            j--;
        }
        ans = max(ans, j);

        while (colors[i] == colors[n - 1]) {
            i++;
        }
        ans = max(ans, n - 1 - i);

        return ans;
    }
};
