class Solution {
public:
    int maxScore(vector<int>& A) {
        reverse(begin(A), end(A));
        int res = 0, ma = 0;
        for(int i = 0; i < A.size() - 1; i++) {
            ma = max(ma, A[i]);
            res += ma;
        }
        return res;
    }
};