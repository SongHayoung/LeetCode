class Solution {
public:
    int findValueOfPartition(vector<int>& A) {
        sort(begin(A), end(A));
        int res = INT_MAX;
        for(int i = 0; i < A.size() - 1; i++) res = min(res, A[i+1] - A[i]);
        return res;
    }
};
