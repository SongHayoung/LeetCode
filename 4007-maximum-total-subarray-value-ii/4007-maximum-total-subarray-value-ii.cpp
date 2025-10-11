class Solution {
    struct Agg {
        vector<long long> v, c, pc, ps;
        long long sumAll = 0;
        void push(int x, bool isMax) {
            long long cnt = 1;
            if (isMax) {
                while (!v.empty() && v.back() <= x) {
                    sumAll -= v.back() * c.back();
                    cnt += c.back();
                    v.pop_back(); c.pop_back(); pc.pop_back(); ps.pop_back();
                }
            } else {
                while (!v.empty() && v.back() >= x) {
                    sumAll -= v.back() * c.back();
                    cnt += c.back();
                    v.pop_back(); c.pop_back(); pc.pop_back(); ps.pop_back();
                }
            }
            v.push_back(x); c.push_back(cnt);
            sumAll += 1ll * x * cnt;
            pc.push_back((pc.empty() ? 0 : pc.back()) + cnt);
            ps.push_back((ps.empty() ? 0 : ps.back()) + 1ll * x * cnt);
        }
        long long sumLast(long long X) {
            if (X <= 0) return 0;
            long long total = pc.empty() ? 0 : pc.back();
            if (X >= total) return ps.empty() ? 0 : ps.back();
            long long base = total - X;
            int idx = upper_bound(pc.begin(), pc.end(), base) - pc.begin();
            long long take = pc[idx] - base;
            long long res = v[idx] * take;
            res += ps.back() - ps[idx];
            return res;
        }
    };

    long long helper1(vector<int>& A, long long x) {
        long long n = A.size(), l = 0, res = 0;
        deque<int> ma, mi;
        for (int r = 0; r < n; ++r) {
            while (!ma.empty() and A[ma.back()] <= A[r]) ma.pop_back();
             ma.push_back(r);
            while (!mi.empty() and A[mi.back()] >= A[r]) mi.pop_back();
            mi.push_back(r);
            while (!ma.empty() and !mi.empty() && A[ma.front()] - A[mi.front()] >= x) {
                if (ma.front() == l) ma.pop_front();
                if (mi.front() == l) mi.pop_front();
                ++l;
            }
            res += l;
        }
        return res;
    }

    long long helper2(vector<int>& a, int T) {
        int n = a.size(), l = 0;
        deque<int> ma, mi;
        Agg Amax, Amin;
        long long res = 0;
        for (int r = 0; r < n; ++r) {
            Amax.push(a[r], true);
            Amin.push(a[r], false);
            while (!ma.empty() and a[ma.back()] <= a[r]) ma.pop_back();
            ma.push_back(r);
            while (!mi.empty() and a[mi.back()] >= a[r]) mi.pop_back();
            mi.push_back(r);
            while (!ma.empty() and !mi.empty() && a[ma.front()] - a[mi.front()] > T) {
                if (ma.front() == l) ma.pop_front();
                if (mi.front() == l) mi.pop_front();
                ++l;
            }
            int L = l;
            long long X = (L <= r) ? (r - L + 1) : 0;
            long long sumMaxLeft = Amax.sumAll - Amax.sumLast(X);
            long long sumMinLeft = Amin.sumAll - Amin.sumLast(X);
            res += (sumMaxLeft - sumMinLeft - 1ll * T * L);
        }
        return res;
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long l = 0, r = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()), res = 0;  
        while (l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper1(nums, m) >= k;
            if(ok) {
                l = m + 1;
                res = m;
            } else r = m - 1;
        }
        return helper2(nums,res) + res * k;
    }
};