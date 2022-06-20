class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size(), p = n - 1;
        for(int i = n - 1; i > 0; i--) {
            if(A[i] < A[i - 1]) {
                p = i - 1;
                break;
            }
        }
        if(p == n - 1) return A;
        
        int p2 = p + 1 == n ? p : p + 1;
        for(int i = p + 1; i < n; i++) {
            if(A[i] < A[p]) {
                if(A[i] > A[p2])
                    p2 = i;
            }
        }
        swap(A[p2], A[p]);
        return A;
    }
};