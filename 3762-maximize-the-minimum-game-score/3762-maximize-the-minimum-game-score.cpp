class Solution {
    bool helper(vector<int>& A, long long k, long long limit) {
        long long prv = 0, i = 0;
        for(; i < A.size() and k >= 0; i++) {
            long long need = prv ? (prv + A[i-1] - 1) / A[i-1] : 0;
            k -= 2 * need;
            if(k < 0) break;
            if(i + 1 != A.size()) {
                k -= 1;
                prv = max(0ll, limit - (need + 1) * A[i]);
            } else {
                long long now = max(0ll, limit - need * A[i]);
                long long req = (now + A[i] - 1) / A[i];
                if(req) {
                    if(k < 2 * req - 1) return false;
                    k -= (2 * req - 1);
                }
            }
        }
        return i == A.size() and k >= 0;
    }
public:
    long long maxScore(vector<int>& points, int m) {
        long long l = 0, r = LLONG_MAX, res = 0;
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            bool ok = helper(points,m,mid);
            if(ok) {
                l = mid + 1;
                res = mid;
            } else r = mid - 1;
        }
        return res;
    }
};

