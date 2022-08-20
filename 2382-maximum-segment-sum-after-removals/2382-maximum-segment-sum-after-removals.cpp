class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& A, vector<int>& Q) {
        long long n = A.size(), ma = 0;
        vector<long long> l(n), r(n), sum(n), res(n);
        for(int i = 0; i < n; i++) l[i] = r[i] = i;
        for(int i = Q.size() - 1; i >= 0; i--) {
            res[i] = ma;
            sum[Q[i]] += A[Q[i]];
            int left = Q[i], right = Q[i];
            if(Q[i] + 1 < n and sum[Q[i] + 1]) {
                right = r[Q[i] + 1];
                sum[Q[i]] += sum[Q[i] + 1];
            }
            if(Q[i] - 1 >= 0 and sum[Q[i] - 1]) {
                left = l[Q[i] - 1];
                sum[Q[i]] += sum[Q[i] - 1];
            }
            r[right] = r[left] = right;
            l[right] = l[left] = left;
            sum[left] = sum[right] = sum[Q[i]];
            ma = max(ma, sum[Q[i]]);
        }
        return res;
    }
};