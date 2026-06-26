class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        map<long long, int> preSumMap;
        long long sum = 0;
        int count = 0;

        preSumMap[0] = 1;      // Empty prefix

        for (int i = 0; i < a.size(); i++) {
            sum += a[i];

            if (preSumMap.find(sum - k) != preSumMap.end()) {
                count += preSumMap[sum - k];
            }

            preSumMap[sum]++;
        }

        return count;
    }
};
