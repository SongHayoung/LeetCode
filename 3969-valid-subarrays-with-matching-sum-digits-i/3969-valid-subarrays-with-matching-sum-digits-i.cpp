class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick() {}
        Fenwick(int n) : n(n), bit(n + 1) {}

        void add(int i, int v) {
            i++;
            while(i <= n) {
                bit[i] += v;
                i += i & -i;
            }
        }

        int sum(int i) {
            int res = 0;
            i++;
            while(i > 0) {
                res += bit[i];
                i -= i & -i;
            }
            return res;
        }

        int query(int l, int r) {
            if(l > r) return 0;
            return sum(r) - (l ? sum(l - 1) : 0);
        }
    };

    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();

        vector<long long> pre(n + 1);
        for(int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        vector<long long> vals = pre;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<Fenwick> mp;
        for(int i = 0; i < 10; i++) {
            mp.emplace_back(vals.size());
        }

        auto idx = [&](long long v) {
            return lower_bound(vals.begin(), vals.end(), v) - vals.begin();
        };

        auto countRange = [&](int mod, long long le, long long ri) {
            int l = lower_bound(vals.begin(), vals.end(), le) - vals.begin();
            int r = upper_bound(vals.begin(), vals.end(), ri) - vals.begin() - 1;
            if(l > r) return 0;
            return mp[mod].query(l, r);
        };

        long long maxSum = pre.back();
        long long res = 0;

        mp[pre.back() % 10].add(idx(pre.back()), 1);

        for(int i = n - 1; i >= 0; i--) {
            int need = (pre[i] + x) % 10;

            for(long long base = 1; base <= maxSum; base *= 10) {
                long long L = 1LL * x * base;
                long long R = 1LL * (x + 1) * base - 1;

                if(L > maxSum) break;
                R = min(R, maxSum);

                res += countRange(need, pre[i] + L, pre[i] + R);
            }

            mp[pre[i] % 10].add(idx(pre[i]), 1);
        }

        return res;
    }
};