class Solution {
public:
    int maxScore(vector<int>& A, int k) {
        int sum = 0, res = 0, n = A.size();
        for(int i = 0; i < k; i++)
            sum += A[i];
        res = max(res, sum);
        for(int j = k - 1, i = n - 1; j >= 0; i--,j--) {
            sum += A[i] - A[j];
            res = max(res, sum);
        }
        return res;
    }
};