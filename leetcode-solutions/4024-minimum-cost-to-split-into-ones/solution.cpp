class Solution {
public:
    int minCost(int n){
        return n*(n-1)/2;
    }

    
    // int minCost(int n) {
    //     int cost = 0;
    //     int curr = n;
    //     while(curr>1){
    //         cost+=curr-1;
    //         curr--;
    //     }
    //     return cost;
    // }
};
