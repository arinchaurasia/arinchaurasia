class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        vector<string> copy = words;
        unordered_map<string, int> prefixMap;

        for (int i = 0; i < copy.size(); i++) {
            if (copy[i].length() >= k) {
                string prefix = copy[i].substr(0, k);
                prefixMap[prefix] += 1;
            }
        }
        vector<int> counts;
        for (auto pair : prefixMap) {
            counts.push_back(pair.second);
        }

        int groups = 0;
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] >= 2) {
                groups++;
            }
        }

        return groups;
    }
};
