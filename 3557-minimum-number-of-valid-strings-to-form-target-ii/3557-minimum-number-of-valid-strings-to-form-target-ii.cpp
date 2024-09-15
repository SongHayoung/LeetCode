struct Seg {
    long long mi, ma, val, lazy;
    Seg *left, *right;
    Seg(long long l, long long r) : mi(l), ma(r), val(INT_MAX), lazy(INT_MAX), left(nullptr), right(nullptr) {
        if(l^r) {
            long long m = l + (r - l) / 2;
            left = new Seg(l,m);
            right = new Seg(m+1,r);
        }
    }
    void propagate() {
        if(lazy != INT_MAX) {
            val = min(val, lazy);
            if(left) left->lazy = min(left->lazy, lazy);
            if(right) right->lazy = min(right->lazy, lazy);
            lazy = INT_MAX;
        }
    }
    long long query(long long x) {
        propagate();
        if(mi == x and x == ma) return val;
        long long m = mi + (ma - mi) / 2;
        if(x <= m) return left->query(x);
        return right->query(x);
    }
    void update(long long l, long long r, long long x) {
        propagate();
        if(l <= mi and ma <= r) {
            lazy = min(lazy, x);
            propagate();
            return;
        }
        if(l > ma or r < mi) return;
        left->update(l,r,x);
        right->update(l,r,x);
        val = min(left->val, right->val);
    }
};
class Solution {
public:
    long long mod = 1e9 + 7, base = 131;
    long long query(vector<unordered_set<long long>>& rh, vector<long long>& h, vector<long long>& p, long long pos) {
        long long l = pos, r = p.size() - 2, res = -1;
        auto qry = [&](long long l, long long r) {
            long long len = r - l + 1;
            long long val = (h[r+1] - h[l] * p[len] % mod + mod) % mod;
            return rh[len-1].count(val);
        };
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = qry(pos,m);
            if(ok) {
                l = m + 1;
                res = max(res, m);
            } else r = m - 1;
        }
        return res;
    }
    int minValidStrings(vector<string>& words, string target) {
        vector<unordered_set<long long>> rh(50505);
        for(auto& w : words) {
            long long now = 0;
            for(int i = 0; i < w.length(); i++) {
                now = (now * base + w[i] - 'a') % mod;
                rh[i].insert(now);
            }
        }
        vector<long long> hash(target.length() + 1), po(target.length() + 1);
        po[0] = 1;
        for(int i = 0; i < target.length(); i++) {
            po[i+1] = po[i] * base % mod;
            hash[i+1] = (hash[i] * base + target[i] - 'a') % mod;
        }
        Seg* seg = new Seg(0,target.length());
        seg->update(0,0,0);
        for(int i = 0; i < target.length(); i++) {
            long long val = seg->query(i);
            if(val == INT_MAX) continue;
            long long best = query(rh,hash,po,i);
            if(best == -1) continue;
            seg->update(i+1,best+1,seg->query(i) + 1);
        }
        long long res = seg->query(target.length());
        return res >= INT_MAX ? -1 : res;
    }
};
