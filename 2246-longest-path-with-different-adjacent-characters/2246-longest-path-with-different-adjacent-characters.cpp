class Solution {
    int dfs(vector<vector<int>>& adj, int& res, int u, string& s) {
        vector<int> best{0,0};
        for(auto& v : adj[u]) {
            int sub = dfs(adj, res, v, s);
            if(s[v] == s[u]) continue;
            best.push_back(sub);
            sort(rbegin(best), rend(best));
            best.pop_back();
        }
        res = max(res, best[0] + best[1] + 1);
        return best[0] + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> adj(s.length());
        for(int i = 1; i < parent.size(); i++) {
            adj[parent[i]].push_back(i);
        }
        int res = 0;
        dfs(adj,res,0,s);
        return res;
    }
};
