class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char, int> mp;
        int countL = 0, countR = 0, count_ = 0;
        for (char& ch : moves) {
            mp[ch]++;
        }
        for (auto& ch : mp) {
            if (ch.first == 'L') {
                countL = ch.second;
            }
            if (ch.first == 'R') {
                countR = ch.second;
            }
            if (ch.first == '_') {
                count_ = ch.second;
            }
        }
        return abs(countL - countR) + count_;
    }
};
