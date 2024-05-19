class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int res = 0, n = A.size();
        for(int l = 0, r = 0; l < n and r < n; l++) {
            if(r < l) r = l;
            while(r < n and (A[r] == 1 or k)) {
                if(A[r] == 0) k--;
                r++;
            }
            res = max(res, r - l);
            if(A[l] == 0 and r != l) k++;
        }
        return res;
    }
};