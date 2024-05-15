class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& A) {
        sort(begin(A), end(A));
        A[0] = 1;
        int res = 1;
        for(int i = 1; i < A.size(); i++) {
            res = min(res + 1, A[i]);
        }
        return res;
    }
};