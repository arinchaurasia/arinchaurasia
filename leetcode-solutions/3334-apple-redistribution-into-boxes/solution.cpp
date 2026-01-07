class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0, usedCapacity = 0, boxes = 0;
        for (int a : apple) {
            totalApples += a;
        }
        sort(capacity.begin(), capacity.end(), greater<int>());

        for (int c : capacity) {
            usedCapacity += c;
            boxes++;
            if (usedCapacity >= totalApples) {
                return boxes;
            }
        }
        return boxes;
    }
};
