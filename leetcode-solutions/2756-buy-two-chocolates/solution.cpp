class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int total = money - (prices[0] + prices[1]);
        if (total >= 0)
            return total;
        else
            return money;
    }
};
