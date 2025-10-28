struct Seg {
    int mi, ma, lazy, mn, mx;
    Seg *left, *right;
    Seg(int l, int r) : mi(l), ma(r), lazy(0), mn(0), mx(0), left(nullptr), right(nullptr) {
        if (l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(l, m);
            right = new Seg(m + 1, r);
        }
    }
    void apply(int v) { mn += v; mx += v; lazy += v; }
    void pushDown() {
        if (!lazy) return;
        if (left) { left->apply(lazy); right->apply(lazy); }
        lazy = 0;
    }
    void pull() { mn = min(left->mn, right->mn); mx = max(left->mx, right->mx); }
    void update(int l, int r, int x) {
        if (r < mi || ma < l) return;
        if (l <= mi && ma <= r) { apply(x); return; }
        pushDown();
        left->update(l, r, x);
        right->update(l, r, x);
        pull();
    }
    int query(int l, int r, int t) {
        if (r < mi || ma < l) return -1;
        if (mn > t || mx < t) return -1;
        if (mi == ma) return mi;
        pushDown();
        int res = left->query(l, r, t);
        if (res != -1) return res;
        return right->query(l, r, t);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = (int)nums.size();
        Seg* seg = new Seg(0, n - 1);
        vector<int> last(101010, -1);
        int evenTot = 0, oddTot = 0, best = 0;
        for (int r = 0; r < n; ++r) {
            int x = nums[r], p = last[x];
            int sign = x & 1 ? -1 : 1;
            if (p == -1) {
                if (r + 1 <= n - 1) seg->update(r + 1, n - 1, sign);
                if ((x & 1) == 0) ++evenTot; else ++oddTot;
            } else {
                if (p + 1 <= r) seg->update(p + 1, r, -sign);
            }
            last[x] = r;
            int l = seg->query(0, r, evenTot - oddTot);
            if (l != -1) best = max(best, r - l + 1);
        }
        return best;
    }
};