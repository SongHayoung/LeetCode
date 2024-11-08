class Solution {
public:
    vector<int> arraysIntersection(vector<int>& A, vector<int>& B, vector<int>& C) {
        int i = 0, j = 0, k = 0;
        int n = A.size(), m = B.size(), o = C.size();
        vector<int> res;
        
        while(i < n and j < m and k < o) {
            if(A[i] == B[j] and B[j] == C[k]) {
                res.push_back(A[i]);
                i++,j++,k++;
            } else {
                if(A[i] <= B[j] and A[i] <= C[k]) i++;
                else if(B[j] <= A[i] and B[j] <= C[k]) j++;
                else k++;
            }
            
        }
        
        return res;
    }
};