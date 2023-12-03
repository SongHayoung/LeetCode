class Solution {
public:
    vector<int> findPeaks(vector<int>& A) {
        vector<int> res;
        for(int i = 1; i < A.size() - 1; i ++) {
            if(A[i] > A[i-1] and A[i] > A[i+1]) res.push_back(i);
        }
        return res;
    }
};