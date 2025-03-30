struct Seg {
    int mi, ma, best;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), best(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void update(int n, int x) {
        if(mi <= n and n <= ma) {
            best = max(best, x);
            if(left) left->update(n,x);
            if(right) right->update(n,x);
        }
    }
    int query(int l, int r) {
        if(l <= mi and ma <= r) return best;
        if(l > ma or r < mi) return 0;
        return max(left->query(l,r), right->query(l,r));
    }
};
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> le(n,0), ri(n,n - 1);
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) le[i] = le[i-1];
            else le[i] = i;
        }
        for(int i = n - 2; i >= 0; i--) {
            if(s[i] == s[i+1]) ri[i] = ri[i+1];
            else ri[i] = i;
        }
        auto canApply = [&](int l, int r) {
            if(l >= n or r < 0 or l >= r) return false;
            return 0 <= l and l < n and 0 <= r and r < n and le[l] != le[r];
        };
        auto queryLeftMost = [&](int l, int r) {
            int res = ri[l] - l + 1;
            l = ri[ri[l] + 1] + 1;
            res += min(r, ri[l]) - l + 1;
            return res;
        };
        auto queryRightMost = [&](int l, int r) {
            int res = r - le[r] + 1;
            r = le[le[r] - 1] - 1;
            res += r - max(l, le[r]) + 1;
            return res;
        };
        vector<int> pos, vals;
        for(int i = 0; i < n; i++) {
            if(i and s[i] == s[i-1]) continue;
            if(s[i] == '1') continue;
            pos.push_back(i);
            vals.push_back(ri[i] - le[i] + 1);
        }
        int cnt = count(begin(s), end(s), '1');
        if(pos.size() <= 1) return vector<int>(queries.size(), cnt);

        for(int i = 0; i < vals.size() - 1; i++) vals[i] += vals[i+1];
        Seg* seg = new Seg(pos,0,pos.size() - 1);
        for(int i = 0; i < vals.size(); i++) seg->update(pos[i], vals[i]);

        vector<int> res;
        for(auto& q : queries) {
            int l = q[0], r = q[1];
            if(s[l] == '1') l = ri[l] + 1;
            if(s[r] == '1') r = le[r] - 1;
            if(canApply(l,r)) {
                int now = max(queryLeftMost(l,r), queryRightMost(l,r));
                l = ri[ri[l] + 1] + 1;
                r = le[le[r] - 1] - 1;
                if(l <= r and le[l] != le[r]) {
                    now = max(now, seg->query(l,le[r] - 1));
                }
                res.push_back(cnt + now);
            } else res.push_back(cnt);
        }
        return res;
    }
};
