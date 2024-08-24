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
        int res = 0;
        int res2 = 0;
        for(int i = 1, j = A.size() - 2; i < A.size()-1; i++,j--) {
            res += A[i + 1] - A[i] - 1;
            res2 += A[j] - A[j-1] - 1;
        }
        return max(res,res2);
    }
public:
    vector<int> numMovesStonesII(vector<int>& A) {
        sort(begin(A), end(A));
        return {mi(A), ma(A)};
    }
};