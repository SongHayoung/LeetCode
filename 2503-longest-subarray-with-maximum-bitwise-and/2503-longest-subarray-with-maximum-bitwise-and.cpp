class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int ma = *max_element(begin(A), end(A));
        int l = 0, r = 0, n = A.size(), res = 0;
        while(r < n) {
            while(r < n and A[l] == A[r]) r++;
            if(A[l] == ma) res = max(res, r - l);
            l = r;
        }
        return res;
    }
};