
struct Med {
    multiset<long long> ms;
    multiset<long long>::iterator it;

    void insert(long long x) {
        ms.insert(x);
        if (ms.size() == 1) {
            it = ms.begin();
        } else {
            if (ms.size() % 2 == 1) {
                if (*it <= x) ++it;
            } else {
                if (*it > x) --it;
            }
        }
    }

    void pop(long long x) {
        if (*it == x) {
            if (ms.size() == 1) {
                ms.clear();
            } else {
                if (ms.size() % 2 == 1) {
                    --it;
                    ms.erase(std::next(it));
                } else {
                    ++it;
                    ms.erase(std::prev(it));
                }
            }
        } else {
            auto pos = ms.find(x);
            if (pos == ms.end()) return;
            if (ms.size() % 2 == 1) {
                ms.erase(pos);
                if (*it < x) --it;
            } else {
                ms.erase(pos);
                if (*it > x) ++it;
            }
        }
    }

    long long med() const {
        if (ms.size() % 2 == 1) {
            return *it;
        } else {
            auto next_it = std::next(it);
            return (*it + *next_it) / 2;
        }
    }
};
struct Seg {
    long long mi, ma, sum, cnt;
    Seg *left, *right;
    Seg(vector<int>& A, int l, int r) : mi(A[l]), ma(A[r]), sum(0), cnt(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(A,l,m);
            right = new Seg(A,m+1,r);
        }
    }
    pair<long long,long long> query(int l, int r) {
        if(l <= mi and ma <= r) return {sum,cnt};
        if(l > ma or r < mi) return {0,0};
        auto [lsum, lcnt] = left->query(l,r);
        auto [rsum, rcnt] = right->query(l,r);
        return {lsum + rsum, lcnt + rcnt};
    }
    void update(long long x, long long op) {
        if(mi <= x and x <= ma) {
            sum += x * op;
            cnt += op;
            if(left) left->update(x,op);
            if(right) right->update(x,op);
        }
    }
};
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        vector<long long> cost(nums.size());
        Med* med = new Med();
        vector<int> S = nums;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));
        Seg* seg = new Seg(S,0,S.size() - 1);
        for(int i = 0; i < nums.size(); i++) {
            med->insert(nums[i]);
            seg->update(nums[i], 1);
            if(i + 1 >= x) {
                if(i >= x) {
                    med->pop(nums[i-x]);
                    seg->update(nums[i-x],-1);
                }
                long long m = med->med();
                auto [lsum, lcnt] = seg->query(INT_MIN, m);
                auto [rsum, rcnt] = seg->query(m, INT_MAX);
                cost[i] = abs(lsum - lcnt * m) + abs(rsum - rcnt * m);
            }
        }
        vector<vector<long long>> dp;
        long long res = 1e18;
        for(int i = x - 1; i < nums.size(); i++) {
            vector<long long> now(k, 1e18);
            now[0] = cost[i];
            if(dp.size()) {
                for(int i = 0; i < k; i++) now[i] = min(now[i], dp.back()[i]);
                if(dp.size() >= x) {
                    for(int j = 0; j < k - 1; j++) {
                        now[j+1] = min(now[j+1], dp[dp.size() - x][j] + cost[i]);
                    }
                }
            }
            res = min(res, now.back());
            dp.push_back(now);
        }
        return res;
    }
};