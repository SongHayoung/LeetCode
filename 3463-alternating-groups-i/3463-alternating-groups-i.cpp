class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& A) {
        int res = 0, n = A.size();
        for(int i = 0; i < n; i++) {
            if(A[i] != A[(i+1)%n]) {
                if(A[i] == A[(i+2)%n]) res++;
                else i++;
            }
        }
        return res;
    }
};