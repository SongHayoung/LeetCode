class Solution {
    int dp[50][50][151];
    int solution(vector<vector<int>>& g, int mouse, int cat, int step) {
        if(mouse == 0) return 1;
        if(mouse == cat) return 2;
        if(step == 3 * g.size()) return 0;
        
        if(dp[mouse][cat][step] != -1) return dp[mouse][cat][step];
        dp[mouse][cat][step] = 0;
        int draw = 0, catWin = 0, mouseWin = 0;
        for(auto next : g[step & 1 ? cat : mouse]) {
            if(step & 1 and next == 0) continue;
            int res = solution(g, step & 1 ? mouse : next, step & 1 ? next : cat, step + 1);
            
            if(step & 1 and res == 2) return dp[mouse][cat][step] = 2;
            if(!(step & 1) and res == 1) return dp[mouse][cat][step] = 1;
            if(res == 0) draw++;
            else if(res == 1) mouseWin++;
            else if(res == 2) catWin++;
        }
        if(!(step & 1)) {
            if(mouseWin) dp[mouse][cat][step] = 1;
            else if(draw) dp[mouse][cat][step] = 0;
            else dp[mouse][cat][step] = 2;
        } else {
            if(catWin) dp[mouse][cat][step] = 2;
            else if(draw) dp[mouse][cat][step] = 0;
            else dp[mouse][cat][step] = 1;
        }
        return dp[mouse][cat][step];
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        memset(dp,-1,sizeof(dp));
        return solution(graph, 1, 2, 0);
    }
};