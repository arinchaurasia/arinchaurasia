class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = 0;

        // Find maximum cost
        for (int cost : costs) {
            maxCost = max(maxCost, cost);
        }

        // Counting sort frequency array
        vector<int> count(maxCost + 1, 0);

        for (int cost : costs) {
            count[cost]++;
        }

        int ans = 0;

        // Buy from cheapest to most expensive
        for (int price = 1; price <= maxCost; price++) {
            if (count[price] == 0)
                continue;

            // Maximum bars we can buy at this price
            int canBuy = min(count[price], coins / price);

            ans += canBuy;
            coins -= canBuy * price;

            // No more coins to buy even one bar of this price
            if (coins < price)
                break;
        }

        return ans;
    }
};
