class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        for(int i = 0; i < A.size(); i++) {
            while(0 < A[i] and A[i] <= A.size() and A[A[i]-1] != A[i]) {
                swap(A[i], A[A[i]-1]);
            }
        }
        for(int i = 0; i < A.size(); i++) {
            if(i + 1 != A[i]) return i+1;
        }
        return A.size() + 1;
    }
};