class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);
        vector<vector<int>> history(n, vector<int>(26,0));
        vector<int> counter(n,0);
        int seen = 0;
        int res = 0;
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            counter[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(counter[i] == 0)
                q.push(i);
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            if(vis[node]) continue;
            
            seen++;
            vis[node] = true;
            history[node][colors[node]-'a']++;
            res = max(res, *max_element(history[node].begin(), history[node].end()));
            for(auto near : graph[node]) {
                if(vis[near]) return -1;
                
                if(--counter[near] == 0) q.push(near);
                for(int i = 0; i < 26; i++) {
                    history[near][i] = max(history[near][i], history[node][i]);
                }
            }
        }
        return seen == n ? res : -1;
        
    }
};