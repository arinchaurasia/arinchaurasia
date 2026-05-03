class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    int reverseNum(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    int sumOfPrimesInRange(int n) {
        int r = reverseNum(n);
        
        int low = min(n, r);
        int high = max(n, r);
        
        int sum = 0;
        
        for (int i = low; i <= high; i++) {
            if (isPrime(i)) {
                sum += i;
            }
        }
        
        return sum;
    }
};
