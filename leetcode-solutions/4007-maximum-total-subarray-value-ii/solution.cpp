class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Edge case for a single element array
        if (n == 1) {
            return 0; 
        }

        // --- 1. Sparse Table Precomputation ---
        // Precompute logarithms for O(1) range queries
        vector<int> log_table(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }

        int max_log = log_table[n] + 1;
        vector<vector<int>> st_max(max_log, vector<int>(n));
        vector<vector<int>> st_min(max_log, vector<int>(n));

        // Base level
        for (int i = 0; i < n; i++) {
            st_max[0][i] = nums[i];
            st_min[0][i] = nums[i];
        }

        // Build tables
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_max[j][i] = max(st_max[j - 1][i], st_max[j - 1][i + (1 << (j - 1))]);
                st_min[j][i] = min(st_min[j - 1][i], st_min[j - 1][i + (1 << (j - 1))]);
            }
        }

        // Helper lambda to query max - min in O(1)
        auto get_val = [&](int l, int r) {
            int len = r - l + 1;
            int j = log_table[len];
            int mx = max(st_max[j][l], st_max[j][r - (1 << j) + 1]);
            int mn = min(st_min[j][l], st_min[j][r - (1 << j) + 1]);
            return mx - mn;
        };


        // --- 2. Max-Heap Setup ---
        struct State {
            int val;
            int l;
            int r;
            bool operator<(const State& other) const {
                return val < other.val; // Max-heap based on 'val'
            }
        };

        priority_queue<State> pq;
        unordered_set<long long> visited;

        // Helper to encode (l, r) into a single 64-bit integer
        auto get_key = [](int l, int r) {
            return ((long long)l << 32) | (long long)(unsigned int)r;
        };

        // Initialize with the largest possible subarray spanning [0, n-1]
        pq.push({get_val(0, n - 1), 0, n - 1});
        visited.insert(get_key(0, n - 1));

        long long total_val = 0;


        // --- 3. Extract top K subarrays ---
        while (k > 0 && !pq.empty()) {
            State curr = pq.top();
            pq.pop();

            total_val += curr.val;
            k--;

            // Generate child states by shrinking the window from the left or right
            if (curr.l < curr.r) {
                // Shrink left
                long long key1 = get_key(curr.l + 1, curr.r);
                if (visited.find(key1) == visited.end()) {
                    visited.insert(key1);
                    pq.push({get_val(curr.l + 1, curr.r), curr.l + 1, curr.r});
                }

                // Shrink right
                long long key2 = get_key(curr.l, curr.r - 1);
                if (visited.find(key2) == visited.end()) {
                    visited.insert(key2);
                    pq.push({get_val(curr.l, curr.r - 1), curr.l, curr.r - 1});
                }
            }
        }

        return total_val;
    }
};
