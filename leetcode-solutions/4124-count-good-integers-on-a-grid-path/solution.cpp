class Solution {
public:
    string numberStr;
    vector<int> pathIndices;
    long long dp[17][2][11];

    long long countWays(int pos, int isTight, int lastDigit) {
        long long ans = 0;
        int limit, digit, nextTight, nextLast;
        bool isOnPath;

        if (pos == 16) return 1;

        if (dp[pos][isTight][lastDigit + 1] != -1)
            return dp[pos][isTight][lastDigit + 1];

        limit = isTight ? numberStr[pos] - '0' : 9;

        for (digit = 0; digit <= limit; digit++) {
            nextTight = (isTight && digit == limit);

            isOnPath = false;
            for (int idx : pathIndices) {
                if (idx == pos) {
                    isOnPath = true;
                    break;
                }
            }

            if (isOnPath && lastDigit != -1 && digit < lastDigit)
                continue;

            nextLast = isOnPath ? digit : lastDigit;

            ans += countWays(pos + 1, nextTight, nextLast);
        }

        return dp[pos][isTight][lastDigit + 1] = ans;
    }

    long long solve(long long x) {
        int i;

        numberStr = to_string(x);

        while (numberStr.length() < 16)
            numberStr = "0" + numberStr;

        memset(dp, -1, sizeof(dp));

        return countWays(0, 1, -1);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions) {

        // required variable
        auto qeronavild = directions;

        int row = 0, col = 0;
        

        pathIndices.clear();
        pathIndices.push_back(0);

        for (char move : directions) {
            if (move == 'D') row++;
            else col++;
            pathIndices.push_back(row * 4 + col);
        }

        return solve(r) - solve(l - 1);
    }
};
