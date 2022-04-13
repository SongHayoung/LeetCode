class Solution {
    int formula(int target, int k) {
        return ((target / k) + k - 1) / 2;
    }
    bool verify(int target, int k) {
        int alpha = formula(target, k);
        return k * (2 * alpha - k + 1) == target;
    }
public:
    int consecutiveNumbersSum(int n) {
        int target = n * 2;
        int res = 0;
        for(int k = 1; k * k <= target; k++) {
            if(target % k == 0 and verify(target, k)) {
                res++;
            }
        }
        return res;
    }
};