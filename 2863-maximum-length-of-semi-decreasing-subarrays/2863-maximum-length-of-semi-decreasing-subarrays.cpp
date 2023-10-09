struct Seg{
    int mi, ma, val;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), val(-1), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    int query(int n) {
        if(ma < n) return val;
        if(mi >= n) return -1;
        return max(left->query(n), right->query(n));
    }
    void update(int n, int k) {
        if(mi <= n and n <= ma) {
            val = max(val, k);
            if(left) left->update(n,k);
            if(right) right->update(n,k);
        }
    }
};
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        vector<int> S = nums;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size()-1);
        int res = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            int p = seg->query(nums[i]);
            if(p != -1) res = max(res, p - i + 1);
            seg->update(nums[i], i);
        }
        return res;
    }
};