class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int l = 0, r = 0, n = A.size(), z = 0, res = 0;
        while(r < n) {
            while(r < n and z <= 1) {
                z += A[r++] == 0;
                if(z <= 1)
                    res = max(res, r - l - 1);
            }
            while(r < n and z > 1) {
                z -= A[l++] == 0;
            }
        }
        return res;
    }
};