class Solution {
public:
    int reductionOperations(vector<int>& A) {
        sort(begin(A), end(A));
        int res = 0, n = A.size(), i = n - 1;
        while(i > 0) {
            while(i and A[i] == A[i-1]) i--;
            if(i)
                res += n - i;
            i--;
        }
        return res;
    }
};