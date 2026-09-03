struct Seg {
    int mi, ma;
    long long val;
    Seg *left, *right;

    Seg(vector<int>& A, int l, int r) : mi(l), ma(r), val(A[l]), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(A, l, m);
            right = new Seg(A, m + 1, r);
            val = gcd(left->val, right->val);
        }
    }

    long long __query(int l, int r) {
        if(l > r or r < mi or ma < l) return 0;
        if(l <= mi and ma <= r) return val;
        return gcd(left->__query(l, r), right->__query(l, r));
    }

    long long query(int l, int r, int skip) {
        if(skip < l or skip > r) return __query(l, r);
        return gcd(__query(l, skip - 1), __query(skip + 1, r));
    }
};

class Solution {
    int n;
    Seg* seg;

    int getIndex(int idx, int skip) {
        if(skip != -1 and idx >= skip) return idx + 1;
        return idx;
    }

    int getScore(int skip) {
        int len = n - (skip != -1);
        if(len < 2) return 0;

        long long g = seg->query(0, n - 1, skip);

        int l = 0, r = len - 2;
        while(l < r) {
            int m = l + (r - l) / 2;
            int end = getIndex(m, skip);
            if(seg->query(0, end, skip) == g) r = m;
            else l = m + 1;
        }

        int left = l;
        if(seg->query(0, getIndex(left, skip), skip) != g) return 0;

        l = 0, r = len - 2;
        while(l < r) {
            int m = l + (r - l + 1) / 2;
            int start = getIndex(m + 1, skip);
            if(seg->query(start, n - 1, skip) == g) l = m;
            else r = m - 1;
        }

        int right = l;
        if(seg->query(getIndex(right + 1, skip), n - 1, skip) != g) return 0;

        return max(0, right - left + 1);
    }

public:
    int maxValidSplits(vector<int>& nums) {
        n = nums.size();
        seg = new Seg(nums, 0, n - 1);

        int res = getScore(-1);
        for(int skip = 0; skip < n; skip++) res = max(res, getScore(skip));
        return res;
    }
};