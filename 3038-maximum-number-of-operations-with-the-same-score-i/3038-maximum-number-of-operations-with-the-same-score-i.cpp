class Solution {
public:
    int maxOperations(vector<int>& A) {
        int x = A[0] + A[1];
        int res = 0;
        for(int i = 0; i + 1 < A.size(); i+= 2) {
            if(A[i] + A[i+1] != x) break;
            res += 1;
        }
        return res;
    }
};
