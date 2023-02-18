struct Seg {
    long long mi, ma, sum;
    bool lazy;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(l), ma(r), sum(0), lazy(false), left(nullptr), right(nullptr) {
        if(l != r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
            sum = left->sum + right->sum;
        } else sum = A[l];
    }
    void propagate() {
        if(lazy) {
            sum = (ma - mi + 1) - sum;
            if(left and right) {
                left->lazy = !left->lazy;
                right->lazy = !right->lazy;
            }
            lazy = false;
        }
    }
    void filp(int l, int r) {
        propagate();
        if(mi > r or ma < l) return;
        if(l <= mi and ma <= r) {
            lazy = !lazy;
            propagate();
        } else {
            propagate();
            left->filp(l,r);
            right->filp(l,r);
            sum = left->sum + right->sum;
        }
    }
    long long query(int l, int r) {
        propagate();
        return sum;
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        Seg* seg = new Seg(nums1, 0, nums1.size() - 1);
        long long now = accumulate(begin(nums2), end(nums2), 0ll);
        vector<long long> res;
        for(auto q : queries) {
            long long op = q[0], l = q[1], r = q[2];
            if(op == 1) {
                seg->filp(l,r);
            }
            if(op == 2) {
                now += seg->query(0,nums1.size() - 1) * l;
            }
            if(op == 3) res.push_back(now);
        }
        return res;
    }
};
