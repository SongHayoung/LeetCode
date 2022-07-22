class Solution {
    long long mod = 1337;
    long long palindrome(long long n) {
        string rev = to_string(n);
        reverse(begin(rev), end(rev));
        return stoll(to_string(n) + rev);
    }
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        long long ma = pow(10,n) - 1, mi = ma / 10;
        for(long long i = ma; i > mi; i--) {
            long long pal = palindrome(i);
            for(long long j = ma; j * j >= pal; j--) {
                if(pal % j == 0 and pal / j <= ma) return pal % mod;
            }
        }
        return -1;
    }
};