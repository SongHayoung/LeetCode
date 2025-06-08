long long dp[161][161], freq[26][26];
class Solution {
    long long check(string& a, string& b, long long l, long long r, long long fl) {
        long long res = fl;
        for(int i = l; i <= r; i++) {
            int x = a[i] - 'a', y = b[fl ? r - (i - l) : i] - 'a';
            if(x ^ y) {
                if(freq[y][x]) {
                    --freq[y][x], res++;
                } else ++freq[x][y];
            }
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                res += freq[i][j];
                freq[i][j] = 0;
            }
        }
        return res;
    }
    long long helper(string& a, string& b, long long l, long long r) {
        if(l > r) return 0;
        if(l == r) return a[l] != b[l];
        if(dp[l][r] != -1) return dp[l][r];
        long long& res = dp[l][r] = INT_MAX;
        for(int i = l; i < r; i++) res = min(res, helper(a,b,l,i) + helper(a,b,i+1,r));
        res = min({res, check(a,b,l,r,0), check(a,b,l,r,1)});
        return res;
    }
public:
    int minOperations(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return helper(word1, word2, 0, word1.size() - 1);
    }
};
