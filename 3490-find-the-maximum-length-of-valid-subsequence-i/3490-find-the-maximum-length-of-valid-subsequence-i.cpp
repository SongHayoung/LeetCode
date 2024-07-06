class Solution {
    int helper(vector<int>& A, int a, int b) {
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] % 2 == a) {
                res++;
                swap(a,b);
            }
        }
        return res;
    }
public:
    int maximumLength(vector<int>& A) {
        int res = 0;
        for(int i = 0; i <= 1; i++) for(int j = 0; j <= 1; j++) {
            res = max(res, helper(A,i,j));
        }
        return res;
    }
};