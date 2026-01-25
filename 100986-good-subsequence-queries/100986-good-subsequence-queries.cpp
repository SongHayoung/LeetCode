int __gcd(int x, int y) { return !y ? x : __gcd(y, x % y); }
struct Seg {
    int mi, ma, g, tot, dup;
    Seg *left, *right;
    
    Seg(int l, int r) : mi(l), ma(r), g(0), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(l,m);
            right = new Seg(m+1,r);
        };
    }
    int query(int l, int r) {
        if(l <= mi and ma <= r) return g;
        if(l > ma or r < mi) return 0;
        return __gcd(left->query(l,r), right->query(l,r));
    }
    void update(int n, int x) {
        if(mi <= n and n <= ma) {
            if(mi == n and n == ma) {
                tot += x;
                dup = tot;
                if(tot == 0) g = 0;
                else g = n;
            } else {
                left->update(n,x);
                right->update(n,x);
                g = __gcd(left->g, right->g);
                tot = left->tot + right->tot;
                dup = max(left->dup, right->dup);
            }
        }
    }
    void init() {
        g = tot = dup = 0;
        if(left) left->init();
        if(right) right->init();
    }
} *seg = new Seg(1, 1e5 / 2);
class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        seg->init();
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % p) continue;
            seg->update(nums[i] / p, 1);
        }
        int res = 0, n = nums.size();
        for(auto& q : queries) {
            int idx = q[0], val = q[1];
            if(nums[idx] % p == 0) seg->update(nums[idx] / p, -1);
            nums[idx] = val;
            if(nums[idx] % p == 0) seg->update(nums[idx] / p, 1);
            if(seg->g == 1) {
                if(seg->tot != n) res++;
                else {
                    if(seg->dup >= 2) res++;
                    else {
                        if(seg->query(1,1) == 1) res++;
                        else {
                            for(int skip = 1; skip * p <= 1e5; skip++) {
                                if(seg->query(skip,skip) != skip) continue;
                                if(__gcd(seg->query(1,skip-1), seg->query(skip+1,1e5 / p))== 1) {
                                    res++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
