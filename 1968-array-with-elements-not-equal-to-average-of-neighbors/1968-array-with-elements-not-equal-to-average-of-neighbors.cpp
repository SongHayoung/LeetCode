class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        int n = A.size();
        for(int i = 1; i < n - 1; i++) {
            if(A[i - 1] + A[i + 1] == 2 * A[i])
                swap(A[i], A[i + 1]);
        }
        for(int i = n - 2; i >= 1; i--) {
            if(A[i - 1] + A[i + 1] == 2 * A[i])
                swap(A[i], A[i - 1]);
        }
        return A;
    }
};