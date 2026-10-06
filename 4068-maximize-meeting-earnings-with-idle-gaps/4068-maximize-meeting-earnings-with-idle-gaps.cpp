struct Seg {
    long long mi, ma, val;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), val(LLONG_MIN), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    long long query(int n) {
        if(ma <= n) return val;
        if(mi > n) return LLONG_MIN;
        return max(left->query(n), right->query(n));
    }
    void update(int n, long long x) {
        if(mi <= n and n <= ma) {
            val = max(val,x);
            if(left) left->update(n,x);
            if(right) right->update(n,x);
        }
    }
};
class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        vector<int> S;
        for(auto& m : meetings) {
            S.push_back(m[0]);
            S.push_back(m[1]);
        }
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size()-1);
        long long res = 0;
        for(auto& m : meetings) {
            long long s = m[0], e = m[1], r = m[2];
            long long now = max(r, seg->query(s) + s + r);
            res = max(res, now);
            seg->update(e,now - e);
        }
        return res;
    }
};