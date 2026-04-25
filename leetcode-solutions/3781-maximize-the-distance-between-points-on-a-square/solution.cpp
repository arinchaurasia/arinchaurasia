#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        long long P = 4LL * side;

        // "Unroll" the square boundary into a number line [0, 4*side)
        // Walk: bottom edge -> right edge -> top edge -> left edge
        auto toPerim = [&](int x, int y) -> long long {
            if (y == 0)    return x;
            if (x == side) return side + y;
            if (y == side) return 3LL * side - x;
            return         4LL * side - y;
        };

        vector<long long> t(n);
        for (int i = 0; i < n; i++)
            t[i] = toPerim(points[i][0], points[i][1]);
        sort(t.begin(), t.end());

        // Given a candidate minimum distance d, can we greedily place k points
        // around the perimeter so every consecutive gap (including wrap-around) >= d?
        auto feasible = [&](long long d) -> bool {
            for (int i = 0; i < n; i++) {
                long long start = t[i];
                long long cur   = start;
                int count = 1;

                while (count < k) {
                    long long need = cur + d;

                    // If even the theoretical next slot overshoots a full lap, give up
                    if (need >= start + P) break;

                    // Binary search for the next point at position >= need
                    // Points that "wrapped around" are handled by shifting by P
                    long long searchVal = need < P ? need : need - P;
                    auto it = lower_bound(t.begin(), t.end(), searchVal);

                    if (need < P && it == t.end()) {
                        // No point in the upper part of [0,P); wrap and retry from 0
                        it = lower_bound(t.begin(), t.end(), need - P);
                        if (it == t.end()) break;
                        cur = t[it - t.begin()] + P;
                    } else if (need >= P) {
                        if (it == t.end()) break;
                        cur = t[it - t.begin()] + P;
                    } else {
                        cur = t[it - t.begin()];
                    }

                    // Before counting the last point, verify the closing gap
                    // (last point back to start, going the short way around) is >= d
                    if (count == k - 1 && (start + P - cur) < d) break;

                    count++;
                }

                if (count == k) return true;
            }
            return false;
        };

        // Binary search on the answer
        // Upper bound: spacing k points perfectly evenly = P/k
        long long lo = 1, hi = P / k, ans = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) { ans = mid; lo = mid + 1; }
            else                  hi = mid - 1;
        }

        return (int)ans;
    }
};
