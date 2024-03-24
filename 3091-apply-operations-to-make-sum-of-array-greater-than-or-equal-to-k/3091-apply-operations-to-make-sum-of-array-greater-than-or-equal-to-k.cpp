class Solution {
public:
    int minOperations(int k) {
        int res = k - 1;
        for(int i = 1; i <= k and i <= res; i++) {
            int op = i - 1;
            int mul = max(1, (k + i - 1) / i - 1);
            res = min(res, op + mul);
        }
        return res;
    }
};
