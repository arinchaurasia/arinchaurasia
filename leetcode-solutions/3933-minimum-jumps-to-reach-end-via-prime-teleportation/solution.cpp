class Solution {
public:
    vector<bool> sieve(int mx) {
        vector<bool> prime(mx + 1, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i <= mx; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= mx; j += i) {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> isPrime = sieve(mx);
        unordered_map<int, vector<int>> divisible;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {

                    if (isPrime[p]) {
                        divisible[p].push_back(i);
                    }

                    while (x % p == 0)
                        x /= p;
                }
            }

            if (x > 1 && isPrime[x]) {
                divisible[x].push_back(i);
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;
        unordered_set<int> usedPrime;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1)
                return d;

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }
            int val = nums[i];

            if (isPrime[val] && !usedPrime.count(val)) {
                usedPrime.insert(val);
                for (int nxt : divisible[val]) {

                    if (dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }
            }
        }
        return -1;
    }
};
