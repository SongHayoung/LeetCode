
int __gcdint(int x, int y) { return !y ? x : __gcdint(y, x % y); }
struct Seg {
    int mi,ma,val;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(l), ma(r), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
            val = __gcdint(left->val, right->val);
        } else val = A[l];
    }
    void update(int n, int k) {
        if(mi <= n and n <= ma) {
            if(mi == n and n == ma) val = k;
            else {
                left->update(n,k);
                right->update(n,k);
                val = __gcdint(left->val, right->val);
            }
        }
    }
    int query(int l, int r) {
        if(l <= mi and ma <= r) return val;
        if(l > ma or r < mi) return 0;
        return __gcdint(left->query(l,r), right->query(l,r));
    }
}*seg;
class Solution {
    bool helper(vector<int>& A, int op, int t) {
        queue<int> q;
        auto rollback = [&]() {
            while(q.size()) {
                auto idx = q.front(); q.pop();
                seg->update(idx, A[idx]);
            }
        };
        for(int i = t; i < A.size(); i++) {
            int g = seg->query(i-t,i);
            if(g == 1) continue;
            if(--op < 0) {
                rollback();
                return false;
            }
            seg->update(i,1);
            q.push(i);
            i += (t - 1);
        }
        rollback();
        return true;
    }
public:
    int minStable(vector<int>& nums, int maxC) {
        if(nums.size() - count(begin(nums), end(nums), 1) <= maxC) return 0;
        seg = new Seg(nums,0,nums.size() - 1);
        int l = 1, r = nums.size() - 1, res = nums.size();
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(nums,maxC,m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};