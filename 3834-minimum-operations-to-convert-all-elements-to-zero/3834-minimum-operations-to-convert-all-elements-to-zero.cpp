struct Seg{
    int mi,ma,val;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r): mi(l), ma(r), val(INT_MAX), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
            val = min(left->val, right->val);   
        } else val = A[l];
    }
    int query(int l, int r) {
        if(l <= mi and ma <= r) return val;
        if(l > ma or r < mi) return INT_MAX;
        return min(left->query(l,r), right->query(l,r));
    }
};
class Solution {
    Seg* seg;
    int res;
    unordered_map<int,vector<int>> at;
    void helper(int l, int r) {
        if(l > r) return;
        int mi = seg->query(l,r);
        if(mi) res++;
        vector<int>& S = at[mi];
        auto it = lower_bound(begin(S), end(S), l);
        while(l <= r) {
            if(*it != l) helper(l, min(r, *it - 1));
            l = *it + 1;
            it++;
        }
    }
public:
    int minOperations(vector<int>& nums) {
        seg = new Seg(nums,0,nums.size()-1);
        res = 0;
        at.clear();
        for(int i = 0; i < nums.size(); i++) at[nums[i]].push_back(i);
        for(auto& [_, vec] : at) vec.push_back(INT_MAX - 1);
        helper(0,nums.size() - 1);
        return res;
    }
};