int go[50505][26][3];
long long dp[2][26][3];
class Solution {
public:
    string minCostGoodCaption(string caption) {
        if(caption.size() <= 2) return "";
        int n = caption.size();
        for(int i = 0; i < 26; i++) dp[(n - 1) & 1][i][2] = abs(caption.back() - 'a' - i), dp[(n - 1) & 1][i][0] = dp[(n - 1) & 1][i][1] = INT_MAX;
        for(int i = caption.size() - 2; i >= 0; i--) {
            for(int j = 0; j < 26; j++) {
                int c = abs(caption[i] - 'a' - j);
                for(int k = 0; k < 2; k++) {
                    dp[i&1][j][k] = dp[!(i&1)][j][k+1] + c;
                    go[i][j][k] = j;
                }
                dp[i&1][j][2] = INT_MAX;
                for(int k = 0; k < 26; k++) {
                    long long now = dp[!(i&1)][k][k == j ? 2 : 0] + c;
                    if(dp[i&1][j][2] > now) {
                        dp[i&1][j][2] = now;
                        go[i][j][2] = k;
                    }
                }
            }
        }
        long long cost = INT_MAX, mi = -1, k = 0;
        for(int i = 0; i < 26; i++) {
            if(dp[0][i][0] < cost) {
                cost = dp[0][i][0], mi = i;
            }
        }
        string res = "";
        for(int i = 0; i < caption.size(); i++) {
            res.push_back(mi + 'a');
            if(go[i][mi][k] == mi) {
                k = min(k + 1, 2ll);
            } else mi = go[i][mi][k], k = 0;
        }
        return res;
    }
};