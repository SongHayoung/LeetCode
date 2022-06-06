class Solution {
public:
    int arrangeCoins(int n) {
        long long res = 0, l = 0, r = INT_MAX;
        
        while(l <= r) {
            long long m = l + (r - l) / 2;
            long long sum = m * (m + 1) / 2;
            if(sum <= n) res = max(res, m);
            
            if(sum <= n) l = m + 1;
            else r = m - 1;
        }
        
        return res;
    }
};