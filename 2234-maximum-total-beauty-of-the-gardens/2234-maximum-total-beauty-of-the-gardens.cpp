class Solution {
    map<long long, pair<long long, long long>> pre;
    long long helper(vector<int>& A, long long f, long long t) {
        auto it = pre.upper_bound(t);
        it--;
        auto [cnt,sum] = it->second;
        return cnt * t - sum <= f;
    }
    long long helper(vector<int>& A, long long f, long long p, long long t) {
        if(A.size() == 0) return 0;
        long long l = A[0], r = t - 1, res = l;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(A,f,m);
            if(ok) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        return p * res;
    }
public:
    long long maximumBeauty(vector<int>& A, long long f, int target, int full, int partial) {
        sort(begin(A), end(A));
        long long ok = 0;
        while(A.size() and A.back() >= target) {
            ok++; A.pop_back();
        }
        {
            for(auto& a : A) {
                pre[a].first += 1;
                pre[a].second += a;
            }
            long long cnt = 0, sum = 0;
            for(auto& [k,v] : pre) {
                cnt += v.first;
                sum += v.second;
                v = {cnt,sum};
            }
        }
        long long res = helper(A,f,partial,target) + ok * full;
        while(A.size() and f) {
            int x = A.back(); A.pop_back();
            int d = target - x;
            if(f < d) break;
            if(A.size() and A.back() != x) {
                pre.erase(x);
            } else {
                pre[x].first -= 1;
                pre[x].second -= x;
            }
            ok++; f -= d;
            res = max(res, helper(A,f,partial,target) + ok * full);
        }
        return res;
    }
};