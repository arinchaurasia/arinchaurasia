class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = digit.size();

        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> H(k + 1, 0);
        vector<int> prefSum(k + 1, 0);

        for (int i = 0; i < k; i++) {
            H[i + 1] = (H[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int a = it1 - pos.begin();
            int b = (it2 - pos.begin()) - 1;

            int len = b - a + 1;
            long long sum = prefSum[b + 1] - prefSum[a];

            long long x = (H[b + 1] - H[a] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};
