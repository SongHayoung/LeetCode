class Solution {
public:
    int timeRequiredToBuy(vector<int>& A, int k) {
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            res += min(A[i], A[k] - (bool)(i > k));
        }
        return res;
    }
};