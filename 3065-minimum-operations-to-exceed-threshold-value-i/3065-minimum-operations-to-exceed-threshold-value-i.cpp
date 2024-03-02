class Solution {
public:
    int minOperations(vector<int>& A, int k) {
        sort(begin(A), end(A));
        for(int i = 0; i < A.size(); i++) {
            if(A[i] >= k) return i;
        }
        return A.size();
    }
};