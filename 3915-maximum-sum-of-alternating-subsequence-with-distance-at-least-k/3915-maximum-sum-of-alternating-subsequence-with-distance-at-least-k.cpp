struct Seg {
    long long mi, ma, sum;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), sum(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void update(long long n, long long x) {
        if(mi <= n and n <= ma) {
            sum = max(sum, x);
            if(left) left->update(n,x);
            if(right) right->update(n,x);
        }
    }
    long long query(long long l, long long r) {
        if(l <= mi and ma <= r) return sum;
        if(ma < l or mi > r) return 0;
        return max(left->query(l,r), right->query(l,r));
    }
};
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        vector<int> S = nums;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* less = new Seg(S,0,S.size() - 1), *greater = new Seg(S,0,S.size() - 1);
        long long res = 0, n = nums.size();
        vector<long long> l(n), g(n);
        for(int i = 0; i < n; i++) {
            if(i >= k) {
                less->update(nums[i-k], l[i-k]);
                greater->update(nums[i-k], g[i-k]);
            }
            g[i] = less->query(INT_MIN, nums[i] - 1) + nums[i];
            l[i] = greater->query(nums[i] + 1, INT_MAX) + nums[i];
            res = max({res, g[i], l[i]});
        }
        return res;
    }
};