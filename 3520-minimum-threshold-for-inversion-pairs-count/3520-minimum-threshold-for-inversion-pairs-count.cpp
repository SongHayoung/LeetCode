struct Seg {
    int mi, ma, cnt, id;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), cnt(0), id(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    void validate(int seq) {
        if(id == seq) return;
        id = seq;
        cnt = 0;
    }
    int query(int l, int r, int seq) {
        validate(seq);
        if(l <= mi and ma <= r) return cnt;
        if(l > ma or r < mi) return 0;
        return left->query(l,r,seq) + right->query(l,r,seq);
    }
    void update(int n, int seq) {
        validate(seq);
        if(mi <= n and n <= ma) {
            cnt++;
            if(left) left->update(n,seq);
            if(right) right->update(n,seq);
        }
    }
};
class Solution {
    int seq;
    int helper(vector<int>& A, Seg* seg, int m) {
        int res = 0;
        for(auto& n : A) {
            res += seg->query(n + 1, n + m, seq);
            seg->update(n,seq);
        }
        return res;
    }
public:
    int minThreshold(vector<int>& nums, int k) {
        auto S = nums;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size() - 1);
        int l = 1, r = 1e9, res = INT_MAX;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(nums,seg,m) >= k;
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
            seq++;
        }
        return res == INT_MAX ? -1 : res;
    }
};