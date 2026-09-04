struct Seg {
    long long mi, ma, sum, cnt;
    Seg* left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), sum(0), cnt(0), left(nullptr), right(nullptr) {
        if(l ^ r) {
            int m = l + (r - l) / 2;
            left = new Seg(A, l, m);
            right = new Seg(A, m + 1, r);
        }
    }
    void update(int x, int op) {
        if(mi <= x and x <= ma) {
            sum += x * op;
            cnt += op;
            if(left) left->update(x, op);
            if(right) right->update(x, op);
        }
    }
    long long miK(int k) {
        if(cnt <= k) return sum;
        if(mi == ma) return mi * k;
        if(left->cnt >= k) return left->miK(k);
        return left->sum + right->miK(k - left->cnt);
    }
    long long maK(int k) {
        if(cnt <= k) return sum;
        if(mi == ma) return ma * k;
        if(right->cnt >= k) return right->maK(k);
        return right->sum + left->maK(k - right->cnt);
    }
    long long lowK(int k) {
        if(mi == ma) return mi;
        if(left->cnt >= k) return left->lowK(k);
        return right->lowK(k - left->cnt);
    }
    long long topK(int k) {
        if(mi == ma) return mi;
        if(right->cnt >= k) return right->topK(k);
        return left->topK(k - right->cnt);
    }
};

struct BIT {
    int n;
    vector<int> A;
    BIT(int n) : n(n), A(n + 1) {}
    void update(int p, int v) {
        for(++p; p <= n; p += p & -p) A[p] += v;
    }
    int query(int p) {
        int res = 0;
        for(++p; p; p -= p & -p) res += A[p];
        return res;
    }
};

class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> S = nums;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));

        int m = S.size();

        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = lower_bound(begin(S), end(S), nums[i]) - begin(S);

        vector<int> freq(m);
        for(int p : idx) freq[p]++;

        vector<int> pref(m), before(m + 1);
        for(int i = 0; i < m; i++) {
            pref[i] = freq[i] + (i ? pref[i - 1] : 0);
            before[i + 1] = before[i] + freq[i];
        }

        Seg* out = new Seg(S, 0, m - 1);
        Seg* in = new Seg(S, 0, m - 1);

        BIT bit(m);
        vector<int> inFreq(m);

        for(int x : nums) out->update(x, 1);

        auto add = [&](int i) {
            out->update(nums[i], -1);
            in->update(nums[i], 1);
            bit.update(idx[i], 1);
            inFreq[idx[i]]++;
        };

        auto remove = [&](int i) {
            out->update(nums[i], 1);
            in->update(nums[i], -1);
            bit.update(idx[i], -1);
            inFreq[idx[i]]--;
        };

        long long res = LLONG_MIN;

        auto calc = [&](int l, int r) {
            int len = r - l + 1;
            int outside = n - len;
            int best = 0;

            if(k and outside) {
                int q = lower_bound(begin(pref), end(pref), outside) - begin(pref);
                int p;

                if(before[q] + inFreq[q] >= outside) p = q;
                else p = q + 1;

                int inLess = p ? bit.query(p - 1) : 0;
                int outGreaterEqual = outside - (before[p] - inLess);
                best = min(k, max(inLess, outGreaterEqual));
            }

            long long now = in->sum - in->miK(best) + out->maK(best);
            res = max(res, now);
        };

        for(int l = 0; l < n; l++) {
            if(l == 0) {
                for(int r = 0; r < n; r++) {
                    add(r);
                    calc(l, r);
                }
            } else if(l & 1) {
                remove(l - 1);
                for(int r = n - 1; r >= l; r--) {
                    calc(l, r);
                    if(r > l) remove(r);
                }
            } else {
                remove(l - 1);
                add(l);
                for(int r = l; r < n; r++) {
                    if(r > l) add(r);
                    calc(l, r);
                }
            }
        }

        return res;
    }
};