class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return n;
        if(n == 1) return k;
        int diff = k * (k-1);
        int eq = k;
        for(int i = 2; i < n; i++) {
            int tmp = diff;
            diff = (diff + eq) * (k-1);
            eq = tmp;
        }
        return diff + eq;
    }
};