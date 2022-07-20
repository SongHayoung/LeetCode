class Solution {
public:
    int maxSatisfied(vector<int>& A, vector<int>& B, int k) {
        int ma = 0, res = 0, l = 0, r = 0, now = 0, n = A.size();
        for(int i = 0; i < k; i++) {
            if(B[i] == 0) res += A[i];
            else {
                now += A[i];
                ma = max(now, ma);
            }
        }
        for(int i = k; i < n; i++) {
            if(B[i] == 0) res += A[i];
            else now += A[i];
            if(B[i-k] == 1) now -= A[i-k];
            ma = max(ma, now);
        }
        return res + ma;
    }
};