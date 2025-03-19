class Solution {
public:
    int minOperations(vector<int>& A) {
        int n = A.size(), res = 0;
        for(int i = 0; i < n - 2; i++) {
            if(A[i]) continue;
            A[i] = !A[i];
            A[i+1] = !A[i+1];
            A[i+2] = !A[i+2];
            res++;
        }
        if(A[n-1] == 0 or A[n-2] == 0) return -1;
        return res;
    }
};