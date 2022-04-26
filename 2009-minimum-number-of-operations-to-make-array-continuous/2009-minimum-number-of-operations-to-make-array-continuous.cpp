#define all(a) begin(a), end(a)
class Solution {
public:
    int minOperations(vector<int>& A) {
        int n = A.size(), l = 0, r = 0, res = INT_MAX, dup = 0;
        sort(all(A));
        while(r + 1 < n and A[r + 1] <= A[l] + n - 1) {
            if(A[r] == A[r+1]) dup++;
            r++;
        }
        
        while(l < n) {
            res = min(res,dup + l + n - r - 1);
            if(l + 1 < n and A[l + 1] == A[l]) dup--;
            l++;
            while(r + 1 < n and A[r + 1] <= A[l] + n - 1) {
                if(A[r] == A[r+1]) dup++;
                r++;
            }
        }
        
        return res;
    }
};