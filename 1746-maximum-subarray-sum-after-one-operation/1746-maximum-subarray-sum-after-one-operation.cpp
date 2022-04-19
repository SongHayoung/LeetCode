class Solution {
public:
    int maxSumAfterOperation(vector<int>& A) {
        int n = A.size(), res = 0;
        vector<int> fw(n,0);
        for(int i = 0, sum = 0; i < n; i++) {
            fw[i] = sum = max(sum + A[i], 0);
        }
        for(int i = n - 1, sum = 0; i >= 0; i--) {
            res = max(res, A[i] * A[i] + (i ? fw[i-1] : 0) + sum);
            sum = max(sum + A[i], 0);
        }
        return res;
    }
};