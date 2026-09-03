struct Seg {
    int n, log;
    vector<int> lg;
    vector<vector<int>> st;

    Seg(vector<int>& A) {
        n = A.size();
        lg.resize(n + 1);
        for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        log = lg[n] + 1;
        st.assign(log, vector<int>(n));
        st[0] = A;

        for(int k = 1; k < log; k++) {
            for(int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int __query(int l, int r) {
        if(l > r) return 0;
        int k = lg[r - l + 1];
        return gcd(st[k][l], st[k][r - (1 << k) + 1]);
    }

    int query(int l, int r, int skip) {
        if(l > r) return 0;
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

        int g = seg->query(0, n - 1, skip);

        int l = 0, r = len - 2;
        while(l < r) {
            int m = l + (r - l) / 2;
            int end = getIndex(m, skip);

            if(seg->query(0, end, skip) == g) r = m;
            else l = m + 1;
        }

        int left = l;
        if(seg->query(0, getIndex(left, skip), skip) != g) return 0;

        l = 0;
        r = len - 2;

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
        seg = new Seg(nums);

        int res = getScore(-1);
        for(int skip = 0; skip < n; skip++) {
            res = max(res, getScore(skip));
        }
        return res;
    }
};