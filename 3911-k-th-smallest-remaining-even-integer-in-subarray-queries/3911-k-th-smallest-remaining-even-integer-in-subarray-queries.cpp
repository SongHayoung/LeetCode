struct Seg {
    int mi,ma,cnt,tot;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), cnt(0), tot(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void update(int n, int op) {
        if(mi <= n and n <= ma) {
            cnt += op;
            if(mi == n and n == ma) {
                if(op == 1 and cnt == 1) tot++;
                if(op == -1 and cnt == 0) tot--;
            } else {
                left->update(n,op);
                right->update(n,op);
                tot = left->tot + right->tot;
            }
        }
    }
    int query(long long l, long long r) {
        if(l <= mi and ma <= r) return tot;
        if(l > ma or r < mi) return 0;
        return left->query(l,r) + right->query(l,r);
    }
};
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        vector<array<int,4>> Q;
        for(int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2];
            Q.push_back({l,r,k,i});
        }
        vector<int> res(Q.size()), S = nums;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size()-1);
        int n = nums.size(), sq = sqrt(n), l = 0, r = 0;
        sort(begin(Q), end(Q), [&](auto& a, auto& b) {
            int asq = a[0] / sq, bsq = b[0] / sq;
            if(asq != bsq) return asq < bsq;
            return a[1] < b[1];
        });
        auto update = [&](int idx, int op) {
            if(nums[idx] & 1) return;
            seg->update(nums[idx], op);
        };
        auto qry = [&](int k) {
            long long l = 1, r = 2e9, res = r;
            while(l <= r) {
                long long m = l + (r - l) / 2;
                long long cnt = m - seg->query(2, 2ll * m);
                if(cnt >= k) {
                    res = m * 2;
                    r = m - 1;
                } else l = m + 1;
            }
            return res;
        };
        for(auto& [le,ri,k,idx] : Q) {
            while(r <= ri) update(r++,1);
            while(l > le) update(--l, 1);
            while(r > ri + 1) update(--r,-1);
            while(l < le) update(l++, -1);
            res[idx] = qry(k);
        }

        return res;
    }
};