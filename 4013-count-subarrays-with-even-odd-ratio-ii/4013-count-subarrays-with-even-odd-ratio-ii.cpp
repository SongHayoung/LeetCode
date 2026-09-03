class Solution {
    struct Fenwick {
        int n;
        vector<long long> tree;

        Fenwick(int n) : n(n), tree(n + 1) {}

        void add(int idx, int val) {
            for(; idx <= n; idx += idx & -idx) {
                tree[idx] += val;
            }
        }

        long long sum(int idx) {
            long long res = 0;
            for(; idx > 0; idx -= idx & -idx) {
                res += tree[idx];
            }
            return res;
        }

        long long rangeSum(int l, int r) {
            if(l > r) return 0;
            return sum(r) - sum(l - 1);
        }
    };

public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        vector<long long> pref(n + 1);
        long long even = 0, odd = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) even++;
            else odd++;

            pref[i + 1] = 1LL * b * even - 1LL * a * odd;
        }

        vector<long long> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick fw(vals.size());

        long long res = 0;

        for(int i = 0; i <= n; i++) {
            int idx = lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin() + 1;

            res += fw.rangeSum(idx, vals.size());

            fw.add(idx, 1);
        }

        return res;
    }
};