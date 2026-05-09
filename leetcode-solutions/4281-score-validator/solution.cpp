class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans;
        int score = 0, count = 0;

        for (auto i : events) {
            if (count == 10)
                return {score, count};
            if (i == "0" || i == "1" || i == "2" || i == "3" || i == "4" ||
                i == "6") {
                score = score + stoi(i);
            }
            if (i == "W")
                count++;
            if (i == "WD")
                score++;
            if (i == "NB")
                score++;
        }
        return {score, count};
    }
};
