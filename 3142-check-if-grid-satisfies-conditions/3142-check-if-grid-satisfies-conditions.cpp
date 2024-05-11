class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& A) {
        for(int i = 0; i < A[0].size() - 1; i++) {
            if(A[0][i] == A[0][i+1]) return false;
        }
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i] != A[i+1]) return false;
        }
        return true;
    }
};
