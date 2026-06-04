class Solution {
public:
    int cnt(string &s) {
        int n = s.size();
        int res = 0;
        if (n < 3) return 0;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] > s[i - 1] && s[i] > s[i + 1])
                res++;
            else if (s[i] < s[i - 1] && s[i] < s[i + 1])
                res++;
        }
        return res;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int x = num1; x <= num2; x++) {
            string s = to_string(x);
            ans += cnt(s);
        }
        return ans;
    }
};
