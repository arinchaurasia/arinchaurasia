class Solution {
public:
    int countMonobit(int n) {
        int count = 0;
        if (n >= 0)
            count++;
        for(long long i=1;i<=n;i=(i<<1)|1)
            {
            count++;
            }
        return count;
    }
};
