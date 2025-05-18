class Solution {
    bool helper(vector<int>& A, long long k, long long target) {
        long long cnt = 1, idx = 0, time = 0, n = A.size();
        while(time <= target and idx < n and cnt) {
            if(cnt >= n - idx) {
                time += A[idx];
                idx = n;
                break;
            }
            while(idx < n and cnt and target - A[idx] < time + k) {
                cnt--;
                idx++;
            }
            cnt *= 2;
            time += k;
        }
        return time <= target and idx == n;
    }
public:
    long long minEliminationTime(vector<int>& timeReq, int splitTime) {
        sort(rbegin(timeReq), rend(timeReq));
        long long l = 0, r = LLONG_MAX, res = r;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(timeReq, splitTime, m);
            if(ok) {
                r = m - 1;
                res = m;
            } else l = m + 1;
        }
        return res;
    }
};