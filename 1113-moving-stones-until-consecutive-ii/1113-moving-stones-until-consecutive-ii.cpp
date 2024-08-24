class Solution {
    int mi(vector<int> A) {
        int res = INT_MAX, l = 0, r = 0, n = A.size();
        while(r < n) {
            while(r < n and A[r] < A[l] + n){
                if(r - l + 1 == n - 1 and A[r] - A[l] == n - 2) res = min(res,2);
                else res = min(res, n - (r - l + 1));
                r++;
            }
            l++;
        }
        return res;
    }
    int ma(vector<int> A) {
        int n = A.size();
        return max(A[n-1] - A[1] + 1 - n + 1, A[n-2] - A[0] + 1 - n + 1);
    }
public:
    vector<int> numMovesStonesII(vector<int>& A) {
        sort(begin(A), end(A));
        return {mi(A), ma(A)};
    }
};