
class Solution {
public:
    using ll = long long;

    struct LINE {
        mutable ll k, m, p;
        bool operator<(const LINE& o) const { return k < o.k; }
        bool operator<(ll x) const { return p < x; }
    };

    struct LineContainer : multiset<LINE, less<>> {
        static const ll inf = LLONG_MAX;

        ll div(ll a, ll b) {
            return a / b - ((a ^ b) < 0 && a % b);
        }

        bool isect(iterator x, iterator y) {
            if (y == end()) return x->p = inf, false;
            if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
            else x->p = div(y->m - x->m, x->k - y->k);
            return x->p >= y->p;
        }

        void add(ll m, ll k) {
            auto z = insert({-k, -m, 0}), y = z++, x = y;
            while (isect(y, z)) z = erase(z);
            if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
            while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
        }

        ll query(ll x) {
            auto l = *lower_bound(x);
            return -(l.k * x + l.m);
        }
    };

    ll minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> P(n + 1, 0);
        for (int i = 1; i <= n; i++) P[i] = P[i - 1] + nums[i - 1];

        auto tri = [&](ll s) -> ll {
            return s * (s + 1) / 2;
        };

        const ll INF = 1e18;
        vector<ll> dp(n + 1, INF), dpp(n + 1, INF);
        dp[0] = 0;

        for (int t = 1; t <= k; t++) {
            fill(dpp.begin(), dpp.end(), INF);

            LineContainer hull;

            auto addJ = [&](int j) {
                ll pj = P[j];
                ll a = -pj;
                ll b = dp[j] + pj * (pj - 1) / 2;

                hull.add(b, a);
            };

            addJ(t - 1);

            for (int i = t; i <= n; i++) {
                dpp[i] = tri(P[i]) + hull.query(P[i]);

                if (dp[i] < INF) addJ(i);
            }
            
            dpp.swap(dp);
        }

        return dp[n];
    }
};