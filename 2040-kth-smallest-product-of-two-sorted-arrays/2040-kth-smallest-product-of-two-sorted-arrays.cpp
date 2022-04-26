#define all(a) begin(a), end(a)
class Solution {
    long long mi(vector<int>& A1, vector<int>& A2, vector<int>& B1, vector<int>& B2, int A3, int B3) {
        long long mi = LLONG_MAX;
        if(A1.size() and B2.size())
            mi = min(mi, 1ll * A1[0] * B2.back());
        if(A2.size() and B1.size())
            mi = min(mi, 1ll * A2.back() * B1[0]);
        if(A3 or B3)
            mi = min(mi, 0ll);
        if(A1.size() and B1.size())
            mi = min(mi, 1ll * A1.back() * B1.back());
        if(A2.size() and B2.size())
            mi = min(mi, 1ll * A2[0] * B2[0]);
        return mi;
    }
    
    long long ma(vector<int>& A1, vector<int>& A2, vector<int>& B1, vector<int>& B2, int A3, int B3) {
        long long ma = LLONG_MIN;
        if(A1.size() and B2.size())
            ma = max(ma, 1ll * A1.back() * B2[0]);
        if(A2.size() and B1.size())
            ma = max(ma, 1ll * A2[0] * B1.back());
        if(A3 or B3)
            ma = max(ma, 0ll);
        if(A1.size() and B1.size())
            ma = max(ma, 1ll * A1[0] * B1[0]);
        if(A2.size() and B2.size())
            ma = max(ma, 1ll * A2.back() * B2.back());
        return ma;
    }
    pair<long long, bool> search(vector<int>& A, vector<int>& B, long long t) {
        if(A.size() < B.size())
            return search(B, A, t);
        
        long long res = 0;
        bool has = false;
        
        for(auto& b : B) {
            if(b == 0) {
                if(t >= 0) res += A.size();
                if(t == 0) has = true;
            } else if(b > 0) {
                long long f = floor(1.0 * t / b);
                auto it = upper_bound(all(A), f);
                res += it - begin(A);
                if(it != begin(A) and 1ll * *(--it) * b == t) has = true;
            } else {
                long long f = ceil(1.0 * t / b);
                auto it = lower_bound(all(A),f);
                res += end(A) - it;
                if(it != end(A) and 1ll * *it * b == t) has = true;
            }
        }
        
        return {res, has};
    }
public:
    long long kthSmallestProduct(vector<int>& A, vector<int>& B, long long k) {
       
        
        //long long res = LLONG_MAX, l = mi(A1,A2,B1,B2,A3,B3), r = ma(A1,A2,B1,B2,A3,B3);
        long long res = LLONG_MAX, l = LLONG_MIN/2, r = LLONG_MAX/2;
        while(l <= r) {
            long long m = (l + r) / 2;
            auto [s, h] = search(A,B,m);
            if(s >= k and h) res = min(res, m);
            if(s >= k) r = m - 1;
            else l = m + 1;          
        }
        return res;
        
    }
};