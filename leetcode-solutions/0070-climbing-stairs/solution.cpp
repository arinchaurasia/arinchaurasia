class Solution {
public:

//Space Optimized
int climbStairs(int n) {
  
    if(n==1 || n==2 || n==3) return n;
    int c=3, a = 1, b = 2;
     for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

    return c;

}


//  Bottom Up
// int climbStairs(int n) {
//     if(n==1 || n==2 || n==3) return n;
//     vector<int>dp(n+1);
//     dp[0] = 1;
//     dp[1] = 1;
//     dp[2] = 2;
//     for(int i = 3;i<=n;i++){
//         dp[i] = dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }


// recursion + memo or Top Down
    // int climbStairs(int n) {
    //     if(n<0) return 0;
    //     if(n==0 ) return 1;
    //     vector<int>dp(n+1,-1);

    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n] = climbStairs(n-1)+climbStairs(n-2);

    // }





    // Brute Force
    // int climbStairs(int n) {
    //     if(n<0) return 0;
    //     if(n==0 ) return 1;

    //     return climbStairs(n-1)+climbStairs(n-2);

    // }

    // int climbStairs(int n) {
    //     vector<int> dp(n + 1);
    //     if (n == 1 || n == 2)
    //         return n;
    //     dp[1]=1;
    //     dp[2]=2;
    //     for (int i = 3; i <= n; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }
};
