class Solution {
    static const long long mod = 1000000007;
    long long dp[101][101][101];

    long long dfs(int pos, int i, int j, string& target, vector<vector<int>>& p1, vector<vector<int>>& p2) {
        if(pos == target.size()) return i > 0 && j > 0;

        long long& res = dp[pos][i][j];
        if(res != -1) return res;

        res = 0;
        int c = target[pos] - 'a';

        auto it1 = lower_bound(p1[c].begin(), p1[c].end(), i);
        for(; it1 != p1[c].end(); it1++) {
            res += dfs(pos + 1, *it1 + 1, j, target, p1, p2);
            res %= mod;
        }

        auto it2 = lower_bound(p2[c].begin(), p2[c].end(), j);
        for(; it2 != p2[c].end(); it2++) {
            res += dfs(pos + 1, i, *it2 + 1, target, p1, p2);
            res %= mod;
        }

        return res;
    }

public:
    int interleaveCharacters(string word1, string word2, string target) {
        vector<vector<int>> p1(26), p2(26);

        for(int i = 0; i < word1.size(); i++) {
            p1[word1[i] - 'a'].push_back(i);
        }

        for(int i = 0; i < word2.size(); i++) {
            p2[word2[i] - 'a'].push_back(i);
        }

        memset(dp, -1, sizeof dp);
        return dfs(0, 0, 0, target, p1, p2);
    }
};