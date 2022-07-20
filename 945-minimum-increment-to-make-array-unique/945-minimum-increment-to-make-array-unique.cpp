class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int res = 0, n = A.size();
        sort(begin(A), end(A));
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i-1]) continue;
            res += A[i-1] + 1 - A[i];
            A[i] = A[i-1] + 1;
        }
        return res;
    }
};