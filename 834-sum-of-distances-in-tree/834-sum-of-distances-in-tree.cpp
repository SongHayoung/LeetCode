class Solution {
    vector<vector<int>> adj;
    vector<int> res, count;
    void helper1(int node, int parent) {
        for(auto& near: adj[node]) {
            if(near == parent) continue;
            helper1(near, node);
            count[node] += count[near];
            res[node] += count[near] + res[near];
        }
    }
    void helper2(int node, int parent) {
        for(auto& near: adj[node]) {
            if(near == parent) continue;
            res[near] = res[node] - count[near] + count.size() - count[near];
            helper2(near,node);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n);
        res = vector<int>(n,0);
        count = vector<int>(n,1);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        helper1(0,-1);
        helper2(0,-1);
        return res;
    }
};