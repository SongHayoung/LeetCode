class Solution {
public:
    int countDigitOne(int n) {
        int right = n, left = 0;
        long res = 0, p = 1;
        while(right) {
            int num = right % 10;
            right /= 10;
            res += right * p;
            if(num > 1) {
                res += p;
            } else if(num == 1) {
                res += left + 1;
            }
            left += num * p;
            p *= 10;
        }
        return res;
    }
};