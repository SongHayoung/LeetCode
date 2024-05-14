class Solution {
public:
    int maxNumberOfApples(vector<int>& A) {
        sort(begin(A), end(A));
        for(int i = 0; i < A.size(); i++) {
            if(i) A[i] += A[i-1];
            if(A[i] > 5000) return i;
        }
        return A.size();
    }
};