class Solution {
public:
    void sortColors(vector<int>& A) {
        int n = A.size();
        for(int i = 0, j = 0; i < n; i++) {
            if(A[i] == 0) {
                swap(A[i], A[j++]);
            }
        }
        for(int i = n - 1, j = n - 1; i >= 0; i--) {
            if(A[i] == 2) {
                swap(A[i], A[j--]);
            }
        }
    }
};