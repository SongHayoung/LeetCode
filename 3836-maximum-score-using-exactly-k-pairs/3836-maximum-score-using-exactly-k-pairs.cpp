
long long dp[111][111][111];
bool done[111][111][111];
class Solution {
    long long helper(vector<int>& A, vector<int>& B, int i, int j, int k) {
        if(done[i][j][k]) return dp[i][j][k];
        if(k == 0) return 0;
        done[i][j][k] = 1;
        int ra = A.size() - i, rb = B.size() - j;
        long long& res = dp[i][j][k] = helper(A,B,i+1,j+1,k-1) + 1ll * A[i] * B[j];
        if(ra > k) {
            res = max(res, helper(A,B,i+1,j,k));
        }
        if(rb > k) {
            res = max(res, helper(A,B,i,j+1,k));
        }
        return res;
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        memset(done, 0, sizeof done);
        return helper(nums1, nums2, 0, 0, k);
    }
};