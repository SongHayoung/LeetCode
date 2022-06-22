class Solution {
    long long helper(vector<int>& A, int p) {
        long long psum = 0, mi = 0, ma = 0, res = LLONG_MIN, n = A.size();
        for(int i = p; i < n; i++) {
            if((i - p) & 1) psum -= A[i];
            else psum += A[i];
            res = max({res, psum, psum - mi, psum - ma});
            
            if((i - p) & 1) {
                mi = min(mi, psum);
                ma = max(ma, psum);
            }
        }
        return res;
    }
public:
    long long maximumAlternatingSubarraySum(vector<int>& A) {
        return max(helper(A, 0), helper(A, 1));
    }
};