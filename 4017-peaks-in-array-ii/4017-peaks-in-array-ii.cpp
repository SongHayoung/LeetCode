class Solution {
public:
    struct Node {
        int len;
        long long pref, suff, zero;
    };

    struct SegTree {
        int n;
        vector<Node> seg;

        SegTree(int n = 0) : n(n), seg(4 * n) {}

        Node mergeNode(Node a, Node b) {
            if (a.len == 0) return b;
            if (b.len == 0) return a;

            Node c;
            c.len = a.len + b.len;
            c.pref = a.pref == a.len ? a.len + b.pref : a.pref;
            c.suff = b.suff == b.len ? b.len + a.suff : b.suff;
            c.zero = a.zero + b.zero + a.suff * b.pref;
            return c;
        }

        void build(int node, int l, int r, vector<int>& peak) {
            if (l == r) {
                seg[node].len = 1;
                if (peak[l]) {
                    seg[node].pref = seg[node].suff = seg[node].zero = 0;
                } else {
                    seg[node].pref = seg[node].suff = seg[node].zero = 1;
                }
                return;
            }

            int m = (l + r) / 2;
            build(node * 2, l, m, peak);
            build(node * 2 + 1, m + 1, r, peak);
            seg[node] = mergeNode(seg[node * 2], seg[node * 2 + 1]);
        }

        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                if (val) {
                    seg[node].pref = seg[node].suff = seg[node].zero = 0;
                } else {
                    seg[node].pref = seg[node].suff = seg[node].zero = 1;
                }
                return;
            }

            int m = (l + r) / 2;
            if (idx <= m) update(node * 2, l, m, idx, val);
            else update(node * 2 + 1, m + 1, r, idx, val);

            seg[node] = mergeNode(seg[node * 2], seg[node * 2 + 1]);
        }

        Node query(int node, int l, int r, int ql, int qr) {
            if (qr < l or r < ql) return {0, 0, 0, 0};
            if (ql <= l and r <= qr) return seg[node];

            int m = (l + r) / 2;
            return mergeNode(
                query(node * 2, l, m, ql, qr),
                query(node * 2 + 1, m + 1, r, ql, qr)
            );
        }
    };

    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        auto check = [&](int i) {
            if (i <= 0 or i + 1 >= n) return false;
            return nums[i] > nums[i - 1] and nums[i] > nums[i + 1];
        };

        vector<int> peak(n, 0);
        for (int i = 1; i + 1 < n; i++) {
            peak[i] = check(i);
        }

        SegTree st(n);
        st.build(1, 0, n - 1, peak);

        vector<long long> res;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2];

                if (r - l + 1 < 3) {
                    res.push_back(0);
                    continue;
                }

                int left = l + 1;
                int right = r - 1;
                long long len = right - left + 1;

                auto node = st.query(1, 0, n - 1, left, right);

                long long total = len * (len + 1) / 2;
                long long noPeak = node.zero;

                res.push_back(total - noPeak);
            } else {
                int idx = q[1];
                int val = q[2];

                nums[idx] = val;

                for (int i = idx - 1; i <= idx + 1; i++) {
                    if (i <= 0 or i + 1 >= n) continue;

                    int now = check(i);
                    if (peak[i] != now) {
                        peak[i] = now;
                        st.update(1, 0, n - 1, i, now);
                    }
                }
            }
        }

        return res;
    }
};