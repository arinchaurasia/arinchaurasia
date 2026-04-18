class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int a = maxWeight / w;
        int b = n * n;
        return min(a, b);
    }

    // int k = n*n;
    // int count = 0;
    // for(int i = 1;i<=k;i++){
    //     if(i*w<=maxWeight) count++;
    //     else {
    //         break;
    //     }
    // }
    // return count;
    // }
};
