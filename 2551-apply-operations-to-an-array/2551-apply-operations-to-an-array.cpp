class Solution {
public:
    vector<int> applyOperations(vector<int>& A) {
        int n = A.size();
        vector<int> res;
        for(int i = 0; i < n - 1; i++) {
            if(A[i] == A[i + 1]) {
                A[i] *= 2;
                A[i + 1] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            if(A[i]) res.push_back(A[i]);
        }
        while(res.size() != n) res.push_back(0);
        return res;
    }
};