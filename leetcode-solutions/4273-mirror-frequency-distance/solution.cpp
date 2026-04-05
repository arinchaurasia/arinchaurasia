class Solution {
public:
    int mirrorFrequency(string s) {
        vector<long long> freq(256, 0);
        long long total_sum = 0;
        vector<bool> visited(256, false);

        for (char c : s) {
            freq[c]++;
        }

        string chars = "0123456789abcdefghijklmnopqrstuvwxyz";

        for (char c : chars) {
            if (visited[c]) {
                continue;
            }
            char m;
            if (isdigit(c)) {
                m = '0' + '9' - c;
            } else {
                m = 'a' + 'z' - c;
            }
            total_sum += abs(freq[c] - freq[m]);
            visited[c] = true;
            visited[m] = true;
        }
        return total_sum;
    }
};
