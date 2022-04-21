class Solution {
    vector<int> adj[100001], radj[1000001];
    bool vis1[100001], vis2[100001], vis3[100001];
    int rep[100001];
    vector<int> st;
    
    void dfs1(int u) {
        vis1[u] = true;
        for(auto& v : adj[u]) {
            if(!vis1[v])
                dfs1(v);
        }
        st.push_back(u);
    }
    void dfs2(int u, int r) {
        vis2[u] = true;
        rep[u] = r;
        for(auto& v : radj[u]) {
            if(!vis2[v])
                dfs2(v,r);
        }
    }
    int dfs3(int u, int exc) {
        int res = 0;
        for(auto& v : radj[u])
            if(v != exc)
                res = max(res, dfs3(v, exc));
        return res + 1;
    }
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        for(int i = 0; i < n; i++) {
            adj[i].push_back(fav[i]);
            radj[fav[i]].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            if(!vis1[i])
                dfs1(i);
        }
        while(!st.empty()) {
            auto u = st.back(); st.pop_back();
            if(!vis2[u])
                dfs2(u,u);
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[rep[i]].push_back(i);
        
        int res1 = 0, res2 = 0;
        for(auto& [r, mem] : mp) {
            if(mem.size() == 1) continue;
            if(mem.size() > 2) {
                res1 = max(res1, (int)mem.size());
            }
            if(mem.size() == 2) {
                res2 += dfs3(mem[0], mem[1]) + dfs3(mem[1], mem[0]);
            }
        }
        
        return max(res1, res2);
    }
};