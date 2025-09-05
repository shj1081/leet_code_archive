class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // check if num1 -  k * num2 is sum of (power of 2)
        int k = 1;
        while (true) {
            // subtract num2 for k times (step k)
            long long num = num1 - (long long)num2 * k;
            
            // if we choose i for only 0, at least k is needed (1+1+1+1.... = k)
            if (num < k) return -1;

            // when num of bits <= k, we can make num w/ sum of (power of 2) w/ `k` terms
            else if (bitCnt(num) <= k) return k;

            // check for next step
            ++k;
        }
    }

    // Brian Kernighan’s Algorithm
    int bitCnt(long long num) {
        int cnt = 0;
        while (num != 0) {
            ++cnt;
            num &= (num-1);
        }
        return cnt;
    }
};