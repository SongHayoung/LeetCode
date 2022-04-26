#define all(a) begin(a), end(a)
class Solution {
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
        long long res = LLONG_MAX/2, l = LLONG_MIN, r = LLONG_MAX/2;
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