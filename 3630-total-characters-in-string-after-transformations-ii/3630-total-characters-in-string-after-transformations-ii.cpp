class Solution {
    long mod = 1e9 + 7;
    vector<vector<long>> mul(vector<vector<long>>& A, vector<vector<long>>& B) {
        vector<vector<long>> res(A.size(), vector<long>(B[0].size()));
        for(long i = 0; i < res.size(); i++) {
            for(long j = 0; j < res[0].size(); j++) {
                for(long k = 0; k < B[0].size(); k++) {
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j] % mod) % mod;
                }
            }
        }
        return res;
    }
    vector<vector<long>> pow(vector<vector<long>>& A, long k) {
        vector<vector<long>> res(A.size(), vector<long>(A.size()));
        for(long i = 0; i < res.size(); i++) res[i][i] = 1;
        while(k) {
            if(k & 1) res = mul(res, A);
            A = mul(A,A);
            k>>=1;
        }
        return res;
    }

public:
    long lengthAfterTransformations(string s, long t, vector<int>& nums) {
        vector<vector<long>> mat(26,vector<long>(26)), cnt(1, vector<long>(26));
        for(long i = 0; i < 26; i++) {
            for(long j = 0; j < nums[i]; j++) mat[i][(i+1+j) % 26] = 1;
        }
        for(auto& ch : s) cnt[0][ch-'a']++;
        vector<vector<long>> po = pow(mat, t);
        vector<vector<long>> mat2 = mul(cnt, po);
        long res = 0;
        for(long i = 0; i < 26; i++) res = (res + mat2[0][i]) % mod;
        return res;
    }
};