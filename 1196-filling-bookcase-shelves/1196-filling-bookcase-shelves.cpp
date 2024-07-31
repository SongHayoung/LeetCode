class Solution {
    //width, bookid
    int dp[1001][1001];
    int helper(vector<vector<int>>& b, int &W, int id, int cw, int ch) {
        if(id == b.size()) return ch;
        if(dp[id][cw] != -1) return dp[id][cw];
        dp[id][cw] = INT_MAX;
        if(cw + b[id][0] <= W) { //put beside if possible
            dp[id][cw] = helper(b,W,id + 1, cw + b[id][0], max(ch, b[id][1]));
        }
        dp[id][cw] = min(dp[id][cw], helper(b,W,id+1,b[id][0], b[id][1]) + ch);
        return dp[id][cw];
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        return helper(books, shelfWidth, 0, 0, 0);
    }
};