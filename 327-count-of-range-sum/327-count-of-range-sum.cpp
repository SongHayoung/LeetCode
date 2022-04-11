struct SegmentTree{
    long mi;
    long ma;
    int count;
    SegmentTree* left;
    SegmentTree* right;
    
    SegmentTree(long l, long r) :mi(l), ma(r), count(0), left(NULL), right(NULL) {}
    
    void update(long n) {
        if(mi > n or ma < n) return;
        count++;
        if(left) left->update(n);
        if(right) right->update(n);
    }
    
    int qry(long lo, long hi) {
        if(mi > hi or ma < lo) return 0;
        if(lo <= mi and ma <= hi) return count;
        return (left ? left->qry(lo,hi) : 0) + (right ? right->qry(lo,hi) : 0);
    }
};
class Solution {
    SegmentTree* build(vector<long>& arr, int l, int r) {
        if(l > r) return NULL;
        SegmentTree* sg = new SegmentTree(arr[l], arr[r]);
        if(l == r) return sg;
        int m = l + (r - l) / 2;
        sg->left = build(arr, l, m);
        sg->right = build(arr, m + 1, r);
        return sg;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        unordered_set<int> s{0};
        for(auto n : nums) {
            sum += n;
            s.insert(sum);
        }
        
        vector<long> sums(s.begin(), s.end());
        sort(sums.begin(), sums.end());
        SegmentTree* sg = build(sums, 0, sums.size() - 1);
        int res = 0;
        sum = 0;
        
        for(auto n : nums) {
            sg->update(sum);
            sum += n;
            res += sg->qry(sum - upper, sum - lower);
        }
        return res;
    }
};