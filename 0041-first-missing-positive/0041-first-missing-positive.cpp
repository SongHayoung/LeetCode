class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        for(int i = 0; i < A.size(); i++) {
            while(0 < A[i] and A[i] <= A.size()) {
                int pos = A[i] - 1;
                if(A[pos] != A[i]) swap(A[pos],A[i]);
                else break;
            }
        }
        for(int i = 0; i < A.size(); i++) {
            if(i + 1 != A[i]) return i + 1;
        }
        return A.size() + 1;
    }
};