class Solution {
public:
    static const int MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int sz = A.size();
        Matrix C(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;
                long long cur = A[i][k];
                for (int j = 0; j < sz; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int sz = base.size();
        Matrix res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        // initial state corresponds to length = 2
        vector<long long> init(2 * m);

        for (int i = 0; i < m; i++) {
            init[i] = m - 1 - i;      // up
            init[m + i] = i;          // down
        }

        if (n == 2) {
            long long ans = 0;
            for (auto x : init) ans = (ans + x) % MOD;
            return (int)ans;
        }

        int sz = 2 * m;
        Matrix T(sz, vector<long long>(sz, 0));

        // upNew[i] = suffix(down)
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                T[i][m + j] = 1;
            }
        }

        // downNew[i] = prefix(up)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                T[m + i][j] = 1;
            }
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState(sz, 0);

        for (int i = 0; i < sz; i++) {
            long long val = 0;
            for (int j = 0; j < sz; j++) {
                val = (val + P[i][j] * init[j]) % MOD;
            }
            finalState[i] = val;
        }

        long long ans = 0;
        for (auto x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};
