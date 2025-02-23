class Solution {
    bool helper(vector<long long>& A, int pos, int dis, int k, long long mod) {
        int p = pos;
        while(p + k < A.size() and k--) p = lower_bound(begin(A) + p + 1, end(A), A[p] + dis) - begin(A);
        return k < 0 and p != A.size() and A[pos] + mod - A[p] >= dis;
    }
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> A;
        for(auto& p : points) {
            int x = p[0], y = p[1];
            if(x == 0) A.push_back(y);
            else if(y == side) A.push_back(y + x);
            else if(x == side) A.push_back(2ll * side + (side - y));
            else A.push_back(3ll * side + (side - x));
        }
        sort(begin(A), end(A));
        long long len = 4ll * side, res = len - A.back() + A.front();
        for(int i = 1; i < A.size(); i++) res = min(res, A[i] - A[i-1]);
        for(int i = 0; i <= A.size() - k and A.back() - A[i] > res * (k - 1); i++) {
            int l = res + 1, r = (A.back() - A[i]) / (k - 1);
            while(l <= r) {
                int m = l + (r - l) / 2;
                bool ok = helper(A,i,m,k - 1, len);
                if(ok) {
                    l = m + 1;
                    res = m;
                } else r = m - 1;
            }
        }
        return res;
    }
};