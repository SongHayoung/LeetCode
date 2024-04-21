class Solution {
public:
    void nextPermutation(vector<int>& A) {
        bool fl = true;
        for(int i = 0; i < A.size() - 1 and fl; i++) {
            if(A[i] >= A[i+1]) continue;
            fl = !fl;
        }
        if(fl) {
            sort(begin(A), end(A));
            return;
        }
        int pos = A.size() - 1, pos2 = -1;
        for(int i = A.size() - 1; i >= 1; i--) {
            if(A[i-1] < A[i]) {
                pos = i - 1;
                break;
            }
        }
        for(int i = A.size() - 1; i > pos; i--) {
            if(A[pos] < A[i]) {
                if(pos2 == -1) pos2 = i;
                else if(A[pos2] > A[i]) pos2 = i;
            }
        }
        swap(A[pos], A[pos2]);
        sort(begin(A) + pos + 1, end(A));
    }
};