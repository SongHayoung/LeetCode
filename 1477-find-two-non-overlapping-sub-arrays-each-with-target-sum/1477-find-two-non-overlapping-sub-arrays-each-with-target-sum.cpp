class Solution {
public:
    int minSumOfLengths(vector<int>& A, int target) {
        deque<pair<long long, long long>> dq;
        long long r = 0, sum = 0, n = A.size(), mi = INT_MAX, res = INT_MAX;
        for(int i = 0; i < n; i++) {
            while(dq.size() and dq.front().first <= i) {
                mi = min(mi, dq.front().second);
                dq.pop_front();
            }
            while(r < n and sum < target) sum += A[r++];
            if(sum == target) {
                res = min(res, mi + r - i);
                dq.push_back({r,r - i});
            }
            sum -= A[i];
        }
        return res >= INT_MAX ? -1 : res;
    }
};