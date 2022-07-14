class Solution {
    int helper(vector<int>& A, int st) {
        int res = 0, n = A.size();
        for(int i = st; i < n; i += 2) {
            int mi = INT_MAX;
            if(i - 1 >= 0) mi = min(mi, A[i-1]);
            if(i + 1 < n) mi = min(mi, A[i+1]);
            if(mi <= A[i]) res += A[i] - mi + 1;
        }
        return res;
    }
public:
    int movesToMakeZigzag(vector<int>& A) {
        return min(helper(A,0), helper(A,1));
    }
};