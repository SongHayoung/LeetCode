struct Seg {
    long long mi, ma, pre, suf, best, tot;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(l), ma(r), pre(INT_MIN), suf(INT_MIN), best(INT_MIN), tot(INT_MIN), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
            pushUp();
        } else {
            best = pre = suf = tot = A[l];
        }
    }
    void pushUp() {
        tot = left->tot + right->tot;
        pre = max(left->pre, left->tot + right->pre);
        suf = max(right->suf, left->suf + right->tot);
        best = max({left->best, right->best, left->suf + right->pre});
    }
    void update(int n, int x) {
        if(mi <= n and n <= ma) {
            if(mi == ma) pre = suf = best = tot = x;
            else {
                left->update(n,x);
                right->update(n,x);
                pushUp();
            }
        }
    }
};
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        long long res = *max_element(begin(nums), end(nums));
        if(res <= 0) return res;
        Seg* seg = new Seg(nums,0,nums.size()-1);
        unordered_map<int,vector<int>> pos{{INT_MAX,{}}};
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) pos[nums[i]].push_back(i);
        }
        for(auto& [val,vec] : pos) {
            for(auto& p : vec) seg->update(p,0);
            res = max(res, seg->best);
            for(auto& p : vec) seg->update(p,val);
        }
        return res;
    }
};