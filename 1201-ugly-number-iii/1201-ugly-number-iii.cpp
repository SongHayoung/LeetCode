constexpr auto lcm(auto x, auto... xs)
{
    return ((x = std::lcm(x, xs)), ...);
}
class Solution {
    bool helper(long long n, long long a, long long b, long long c, long long m) {
        long long ab = lcm(a,b), ac = lcm(a,c), bc = lcm(b,c), abc = lcm(a,b,c);
        long long cnt = m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc;
        return cnt >= n;
    }
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int l = 0, r = INT_MAX, res = INT_MAX;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(n,a,b,c,m);
            if(ok) {
                r = m - 1;
                res = m;
            } else l = m + 1;
        }
        return res;
    }
};