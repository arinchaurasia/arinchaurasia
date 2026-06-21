class Solution {
public:
    int maxDistance(string moves) {
        int up = 0, down = 0, left = 0, right = 0, blank = 0;
        for (char c : moves) {
            if (c == 'U')
                up++;
            else if (c == 'D')
                down++;
            else if (c == 'L')
                left++;
            else if (c == 'R')
                right++;
            else
                blank++;
        }
        int dx = right - left;
        int dy = up - down;
        return abs(dx) + abs(dy) + blank;
    }
};
