
static const int MOD = 1000000007;

inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
inline int mul(long long a, long long b) {
    return int(a * b % MOD);
}

vector<vector<int>> matMul(const vector<vector<int>>& A,
                           const vector<vector<int>>& B) {
    int D = A.size();
    vector<vector<int>> C(D, vector<int>(D));
    for (int i = 0; i < D; ++i) {
        for (int k = 0; k < D; ++k) if (A[i][k]) {
                long long v = A[i][k];
                for (int j = 0; j < D; ++j) if (B[k][j]) {
                        C[i][j] = add(C[i][j], mul(v, B[k][j]));
                    }
            }
    }
    return C;
}

vector<vector<int>> matPow(vector<vector<int>> T, long long e) {
    int D = T.size();
    vector<vector<int>> R(D, vector<int>(D));
    for (int i = 0; i < D; ++i) R[i][i] = 1;
    while (e) {
        if (e & 1) R = matMul(R, T);
        T = matMul(T, T);
        e >>= 1;
    }
    return R;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int M = r - l + 1;
        if (n == 1) return M % MOD;
        if (n == 2) {
            return int((long long)M * (M - 1) % MOD);
        }

        int D = 2 * M;
        vector<vector<int>> T(D, vector<int>(D));
        for (int k = 0; k < M; ++k) {
            for (int j = 0; j < k; ++j) {
                T[k][M + j] = 1;
            }
        }
        for (int k = 0; k < M; ++k) {
            for (int j = k + 1; j < M; ++j) {
                T[M + k][j] = 1;
            }
        }

        vector<int> f2(D);
        for (int k = 0; k < M; ++k) {
            f2[k]       = k % MOD;
            f2[M + k]   = (M - 1 - k) % MOD;
        }

        auto Texp = matPow(T, (long long)n - 2);

        long long ans = 0;
        for (int i = 0; i < D; ++i) {
            long long s = 0;
            for (int j = 0; j < D; ++j) {
                if (Texp[i][j]) {
                    s += (long long)Texp[i][j] * f2[j];
                }
            }
            ans = (ans + s % MOD) % MOD;
        }
        return int(ans);
    }
};