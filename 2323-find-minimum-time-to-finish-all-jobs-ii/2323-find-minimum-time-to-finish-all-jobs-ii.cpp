class Solution {
public:
    int minimumTime(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        int n = A.size(), res = 0;
        for(int i = 0; i < n; i++) {
            int t = ceil(1.0 * A[i] / B[i]);
            res = max(res,t);
        }
        return res;
    }
};