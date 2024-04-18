class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int k) {
        int l = 0, r = A.size() - 1, res = -1;
        sort(begin(A), end(A));
        while(l < r) {
            int sum = A[l] + A[r];
            if(sum < k) {
                res = max(res, sum);
                l++;
            } else r--;
        }
        return res;
    }
};