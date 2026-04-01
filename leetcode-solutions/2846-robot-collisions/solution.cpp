class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        // Sort indices based on the positions of the robots
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });

        vector<int> stack; // Stores indices of surviving robots
        for (int i : indices) {
            if (directions[i] == 'R') {
                stack.push_back(i);
            } else {
                // Robot moving Left: check for collisions with robots moving Right
                while (!stack.empty() && directions[stack.back()] == 'R' && healths[i] > 0) {
                    int topIdx = stack.back();
                    if (healths[i] > healths[topIdx]) {
                        // Current Left robot wins
                        healths[topIdx] = 0;
                        healths[i] -= 1;
                        stack.pop_back();
                    } else if (healths[i] < healths[topIdx]) {
                        // Previous Right robot wins
                        healths[i] = 0;
                        healths[topIdx] -= 1;
                    } else {
                        // Both destroyed
                        healths[i] = 0;
                        healths[topIdx] = 0;
                        stack.pop_back();
                    }
                }
                if (healths[i] > 0) {
                    stack.push_back(i);
                }
            }
        }

        sort(stack.begin(), stack.end());

        vector<int> result;
        for (int i : stack) {
            result.push_back(healths[i]);
        }
        return result;
    }
};
