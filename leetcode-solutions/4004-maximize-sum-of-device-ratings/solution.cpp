struct Device {
    long long min1;
    long long min2;
    long long gain;
};
class Solution {
private:
    Device getStats(const vector<int>& devUnits) {
        long long min1 = LLONG_MAX;
        long long min2 = LLONG_MAX;
        if (devUnits.size() == 1) {
            min1 = devUnits[0];
            min2 = 0;
        } else {
            for (int cap : devUnits) {
                if (cap < min1) {
                    min2 = min1;
                    min1 = cap;
                } else if (cap < min2) {
                    min2 = cap;
                }
            }
        }
        return {min1, min2, min2 - min1};
    }

public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        vector<Device> devs(n);
        long long baseSum = 0;
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            devs[i] = getStats(units[i]);
            baseSum += devs[i].min1;
        }
        if (n == 1) {
            return baseSum;
        }
        sort(devs.begin(), devs.end(),
             [](const Device& a, const Device& b) { return a.min1 < b.min1; });
        vector<long long> suffGain(n);
        vector<long long> suffMin2(n);
        suffGain[n - 1] = devs[n - 1].gain;
        suffMin2[n - 1] = devs[n - 1].min2;
        for (int i = n - 2; i >= 0; i--) {
            suffGain[i] = suffGain[i + 1] + devs[i].gain;
            suffMin2[i] = min(suffMin2[i + 1], devs[i].min2);
        }
        long long maxGain = 0;
        for (int i = 0; i < n; i++) {
            long long currGain = suffGain[i] + devs[i].min1 - suffMin2[i];
            maxGain = max(maxGain, currGain);
        }
        return baseSum + maxGain;
    }
};
