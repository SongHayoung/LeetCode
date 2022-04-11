struct SegmentTree{
    long mi,ma;
    SegmentTree* left, *right;
    int count;
    
    SegmentTree(int l, int r): mi(l), ma(r), left(NULL), right(NULL), count(0) {}
    
    void update(int n) {
        if(n < mi or n > ma) return;
        count++;
        if(left) left->update(n);
        if(right) right->update(n);
    }
    
    int qry(long lo, long hi) {
        if(lo > ma or mi > hi) return 0;
        if(lo <= mi and ma <= hi) return count;
        return (left ? left->qry(lo,hi) : 0) + (right ? right->qry(lo,hi) : 0);
    }
};
class Solution {
    SegmentTree* build(vector<int>& arr, int l, int r) {
        if(l > r) return NULL;
        SegmentTree* sg = new SegmentTree(arr[l], arr[r]);
        if(l == r) return sg;
        
        int m = l + (r - l) / 2;
        sg->left = build(arr, l, m);
        sg->right = build(arr, m+1, r);
        return sg;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        auto end = unique(sorted.begin(), sorted.end()) - sorted.begin();

        SegmentTree* sg = build(sorted, 0, end - 1);
        
        long ma = LONG_MIN, cur;
        int res = 0;
        
        for(auto num : nums) {
            cur = num;
            if(cur * 2 < ma) {
                res += sg->qry(cur * 2 + 1, ma);
            }
            sg->update(num);
            ma = max(cur, ma);
        }
        
        return res;
    }
};