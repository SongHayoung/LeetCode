class SparseVector {
public:
    vector<int> n;
    set<int> v;
    SparseVector(vector<int> &nums, int i = 0) : n(nums) {
        for_each(begin(n), end(n), [&](int k) { if (k) v.insert(i); ++i; });
    }
    int dotProduct(SparseVector& vec, vector<int> res = {}) {
        set_intersection(begin(v), end(v), begin(vec.v), end(vec.v), back_inserter(res));
        return accumulate(begin(res), end(res), 0, [&](int s, int i) { return s + n[i] * vec.n[i]; });
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);