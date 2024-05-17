class Solution {
    bool helper(vector<int>& A, int k, int m) {
        for(int i = 0, sum = 0; i < A.size() and k; i++) {
            if(A[i] > m) return false;
            sum += A[i];
            if(sum > m) {
                sum = A[i];
                if(--k == 0) return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 1e9, res = r;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(nums,k,m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};