class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        for (i = 0; i < n - 1;) {
            if (bits[i] == 1)
                i += 2;
            else
                i += 1;
        }
        return i == n - 1;
    }
};
