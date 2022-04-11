class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return{0};
        vector<int> degree(n,0);
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            res.clear();
            int sz = q.size();
            while(sz--) {
                auto node = q.front(); q.pop();
                res.push_back(node);
                for(auto near : adj[node]) {
                    if(--degree[near] == 1) {
                        q.push(near);
                    }
                }
            }
        }
        return res;
        
    }
};