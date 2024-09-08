
class Solution {
    bool helper(vector<int>& A, int d, long long m) {
        long long nxt = A[0] + m;
        for(int i = 1; i < A.size(); i++) {
            long long mi = A[i], ma = mi + d;
            if(nxt > ma) return false;
            nxt = max(nxt, mi) + m;
        }
        return true;
    }
public:
    int maxPossibleScore(vector<int>& start, int d) {
        long long l = 0, r = INT_MAX, res = 0;
        sort(begin(start), end(start));
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(start,d,m);
            if(ok) {
                l = m + 1;
                res = m;
            } else r = m - 1;
        }
        return res;
    }
};