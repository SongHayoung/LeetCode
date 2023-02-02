class Solution {
    bool helper(vector<long long>& A, long long range, long long k, long long m) {
        vector<long long> cut(A.size() + 1);
        long long sum = 0;
        for(int i = 0; i < A.size(); i++) {
            sum += cut[i];
            long long now = sum + A[i];
            if(now >= m) continue;
            long long need = m - now;
            if(need > k) return false;
            k -= need;
            long long r = min(i + 2 * range + 1, (long long) A.size());
            cut[r] -= need;
            sum += need;
        }
        return true;
    }
public:
    long long maxPower(vector<int>& stations, int range, int k) {
        long long l = 0, r = LLONG_MAX, res = 0;
        vector<long long> psum(stations.size());
        for(int i = 0; i < stations.size(); i++) {
            int left = max(0,i - range), right = min((int)stations.size(), i + range);
            psum[left] += stations[i];
            if(right + 1 < psum.size()) psum[right + 1] -= stations[i];
        }
        for(int i = 1; i < psum.size(); i++) psum[i] += psum[i-1];
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(psum, range, k, m);
            if(ok) {
                res = max(res, m);
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
};