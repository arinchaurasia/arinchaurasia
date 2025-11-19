class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool found = true;

        while (found) {
            found = false;
            for (int x : nums) {
                if (x == original) {
                    original *= 2;
                    found = true;
                }
            }
        }

        return original;
    }
};

