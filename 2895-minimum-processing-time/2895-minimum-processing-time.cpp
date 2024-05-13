class Solution {
public:
    int minProcessingTime(vector<int>& A, vector<int>& B) {
        sort(rbegin(A), rend(A));
        sort(begin(B), end(B));
        int res = 0;
        for(int i = 0; i < B.size(); i++) {
            res = max(res, A[i/4] + B[i]);
        }
        return res;
    }
};