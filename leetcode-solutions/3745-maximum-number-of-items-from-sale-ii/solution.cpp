class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        long long min_price = 2e18;
        int max_factor = 0;

        for (const auto& item : items) {
            min_price = min(min_price, (long long)item[1]);
            max_factor = max(max_factor, item[0]);
        }
        vector<int> freq(max_factor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }
        vector<int> multiples_count(max_factor + 1, 0);
        for (int f = 1; f <= max_factor; f++) {
            if (freq[f] == 0) {
                continue;
            }
            for (int m = f; m <= max_factor; m += f) {
                multiples_count[f] += freq[m];
            }
        }
        map<long long, long long> valid_deals;

        for (const auto& item : items) {
            int factor = item[0];
            long long price = item[1];

            if (price < 2 * min_price) {
                long long count = multiples_count[factor] - 1;
                if (count > 0) {
                    valid_deals[price] += count;
                }
            }
        }
        long long total_items = 0;
        long long current_budget = budget;

        for (const auto& [price, count] : valid_deals) {
            if (current_budget < price) {
                break;
            }
            long long take = min(count, current_budget / price);
            total_items += 2 * take;
            current_budget -= take * price;
        }
        total_items += current_budget / min_price;
        return (int)total_items;
    }
};
