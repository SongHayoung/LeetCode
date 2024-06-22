class Solution {
    int helper(vector<int>& A, int x) {
        int res = 0, n = A.size();
        bool fl = false;
        for(int i = 0; i < n; i++) {
            int now = A[i];
            if(fl) now = !now;
            if(now != x) {
                fl = !fl;
                res++;
            }
        }
        return res;
    }
public:
    int minOperations(vector<int>& A) {
        return min(helper(A,1), helper(A,0) + 1);
    }
};
