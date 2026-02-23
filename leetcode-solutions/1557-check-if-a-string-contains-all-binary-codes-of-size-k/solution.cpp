class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k)
            return false;

        int need = 1 << k;
        unordered_set<string> st;

        for (int i = 0; i <= n - k; i++) {
            string sub = s.substr(i, k);
            st.insert(sub);
            if (st.size() == need)
                return true;
        }

        return st.size() == need;
    }
};
