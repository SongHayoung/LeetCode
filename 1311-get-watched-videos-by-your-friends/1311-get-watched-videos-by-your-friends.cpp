class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& adj, int id, int level) {
        int n = adj.size();
        vector<bool> vis(n);
        queue<int> q;
        q.push(id);
        vis[id] = true;
        while(level--) {
            int sz = q.size();
            while(sz--) {
                auto u = q.front(); q.pop();
                for(auto& v : adj[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        
        vector<pair<int, string>> A;
        unordered_map<string, int> mp;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(auto& w : watchedVideos[u])
                mp[w]++;
        }
        for(auto& [k, v] : mp)
            A.push_back({v, k});
        sort(begin(A), end(A));
        
        vector<string> res;
        for(auto& [_, v] : A)
            res.push_back(v);
        return res;
    }
};