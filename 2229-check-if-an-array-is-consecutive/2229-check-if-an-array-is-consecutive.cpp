class Solution {
public:
    bool isConsecutive(vector<int>& A) {
        int mi = *min_element(begin(A), end(A));
        for(int i = 0; i < A.size(); i++) A[i] -= mi;
        for(int i = 0; i < A.size(); i++) {
            while(A[i] != i) {
                if(A[i] >= A.size()) return false;
                if(A[A[i]] == A[i]) return false;
                swap(A[i], A[A[i]]);
            }
        }
        return true;
    }
};