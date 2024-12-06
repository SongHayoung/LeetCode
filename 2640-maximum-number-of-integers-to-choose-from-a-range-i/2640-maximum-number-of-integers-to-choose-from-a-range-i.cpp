class Solution {
    long long sum(long long l, long long r) {
        return r * (r + 1) / 2 - l * (l - 1) / 2;
    }
    long long helper(long long mi, long long ma, long long k) {
        long long l = mi, r = ma, res = l;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            long long s = sum(mi,m);
            if(s <= k) {
                res = max(res,m);
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
public:
    int maxCount(vector<int>& A, int n, long long maxSum) {
        A.push_back(n + 1);
        A.push_back(n + 2);
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A));
        while(A.back() > n + 2) A.pop_back();
        int res = 0, now = 1;
        for(int i = 0; i < A.size() - 1 and maxSum; i++) {
            if(A[i] != now) {
                if(maxSum < now) break;
                long long pick = helper(now, A[i] - 1, maxSum);
                res += pick - now + 1;
                maxSum -= sum(now, pick);
            }
            now = A[i] + 1;
        }
        return res;
    }
};