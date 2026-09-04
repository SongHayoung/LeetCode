class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int res = 0;
        for(int i = max(0,n - k); i <= n + k; i++) {
            if(!(n&i)) res += i;
        }
        return res;
    }
};