class Solution {
    long long count(long long m) {
        long long res = 0;
        while(m >= 5) {
            res += m = m / 5;
        }
        return res;
    }
    long long helper(int k) {
        if(!k) return 5;
        long long l = 0, r = LLONG_MAX;
        while(l <= r) {
            long long m = l + (r-l) / 2, cnt = count(m);
            
            if(cnt > k) r = m - 1;
            else l = m + 1;
        }
        return l - 1;
    }
public:
    int preimageSizeFZF(int k) {
        if(!k) return 5;
        return helper(k) - helper(k-1);
    }
};