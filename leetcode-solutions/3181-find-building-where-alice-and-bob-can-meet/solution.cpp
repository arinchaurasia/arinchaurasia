class Solution {
    int tree[200005]; 

    void build(int i, int l, int r, vector<int>& heights) {
        if (l == r) {
            tree[i] = heights[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, heights);
        build(2 * i + 2, mid + 1, r, heights);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }

    int query(int i, int l, int r, int start, int val) {
        if (r < start || tree[i] <= val) return -1;
        if (l == r) return l;

        int mid = (l + r) / 2;
        int res = query(2 * i + 1, l, mid, start, val);
        if (res == -1) {
            res = query(2 * i + 2, mid + 1, r, start, val);
        }
        return res;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        build(0, 0, n - 1, heights);
        vector<int> ans;

        for (auto& q : queries) {
            int a = q[0], b = q[1];
            if (a > b) swap(a, b);

            if (a == b || heights[b] > heights[a]) {
                ans.push_back(b);
            } else {
                ans.push_back(query(0, 0, n - 1, b + 1, heights[a]));
            }
        }
        return ans;
    }
};
