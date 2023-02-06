class Solution {
    bool helper(vector<int>& A, int k, long long m) {
        int now = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] <= m) i += 1, now += 1;
        }
        return now >= k;
    }
public:
    int minCapability(vector<int>& A, int k) {
        long long l = 0, r = INT_MAX, res = INT_MAX;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(A,k,m);
            if(ok) {
                res = min(res, m);
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};