class Solution {
public:
    int minMovesToSeat(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A));
        sort(begin(B), end(B));
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            res += abs(A[i] - B[i]);
        }
        return res;
    }
};