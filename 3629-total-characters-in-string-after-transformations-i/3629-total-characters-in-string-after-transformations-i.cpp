class Solution {
    long long mod = 1e9 + 7;
    vector<vector<long long>> mul(vector<vector<long long>>& A, vector<vector<long long>>& B) {
        vector<vector<long long>> res(A.size(), vector<long long>(B[0].size()));
        for(int i = 0; i < res.size(); i++) {
            for(int j = 0; j < res[0].size(); j++) {
                for(int k = 0; k < B[0].size(); k++) {
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j] % mod) % mod;
                }
            }
        }
        return res;
    }
    vector<vector<long long>> pow(vector<vector<long long>>& A, long long k) {
        vector<vector<long long>> res(A.size(), vector<long long>(A.size()));
        for(int i = 0; i < res.size(); i++) res[i][i] = 1;
        while(k) {
            if(k & 1) res = mul(res, A);
            A = mul(A,A);
            k>>=1;
        }
        return res;
    }

public:
    int lengthAfterTransformations(string s, int t) {
        vector<vector<long long>> mat(26,vector<long long>(26)), cnt(1, vector<long long>(26));
        for(int i = 0; i < 26; i++) mat[i][(i+1)%26] = 1;
        mat[25][1] = 1;
        for(auto& ch : s) cnt[0][ch-'a']++;
        vector<vector<long long>> po = pow(mat, t);
        vector<vector<long long>> mat2 = mul(cnt, po);
        long long res = 0;
        for(int i = 0; i < 26; i++) res = (res + mat2[0][i]) % mod;
        return res;
    }
};