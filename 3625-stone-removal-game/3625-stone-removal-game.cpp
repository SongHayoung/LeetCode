class Solution {
    long long sum(long long l, long long r) {
        return (r + 1) * r / 2 - l * (l - 1) / 2;
    }
    bool helper(int n, int l, int r) {
        return n >= sum(l,r);
    }
public:
    bool canAliceWin(int n) {
        int l = 1, r = 10, res = 11;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(n,m,10);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res == 11 ? false : (10 - res) % 2 == 0;
    }
};
