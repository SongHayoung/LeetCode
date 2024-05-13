class Solution {
public:
    int integerReplacement(int N) {
        long long res = N - 1, op = 0;
        long long n = N;
        while(n > 1) {
            if(n & 1) {
                if(n & 2) n++;
                else n--;
            } else n /= 2;
            op++;
            res = min(res, op + n - 1);
        }
        return res;
    }
};