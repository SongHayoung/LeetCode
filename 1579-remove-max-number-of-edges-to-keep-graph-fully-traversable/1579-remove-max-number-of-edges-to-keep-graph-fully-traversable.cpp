class Solution {
    int find(vector<int>& g, int n) {
        return g[n] == n ? n : g[n] = find(g, g[n]);
    }
    void uni(vector<int>& g, int a, int b) {
        int pa = find(g, a), pb = find(g, b);
        g[pa] = g[pb] = min(pa, pb);
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> common(n), alice, bob;
        vector<vector<vector<int>>> e(2,vector<vector<int>>());
        for(int i = 0; i < n; i++) common[i] = i;
        int res = 0;
        for(auto edge : edges) {
            if(edge[0] == 1) e[0].push_back({edge[1] - 1,edge[2] - 1});
            else if(edge[0] == 2) e[1].push_back({edge[1] - 1,edge[2] - 1});
            else {
                int pa = find(common, edge[1] - 1), pb = find(common,edge[2] - 1);
                if(pa == pb) res++;
                else uni(common,pa,pb);
            }
        }
        alice = bob = common;
        for(auto edge : e[0]) {
            int pa = find(alice, edge[0]), pb = find(alice, edge[1]);
            if(pa == pb) res++;
            else uni(alice, pa, pb);
        }
        
        for(auto edge : e[1]) {
            int pa = find(bob, edge[0]), pb = find(bob, edge[1]);
            if(pa == pb) res++;
            else uni(bob, pa, pb);
        }
        
        int sum = 0;
        for(int i = 0; i < n and !sum; i++) {
            sum += find(alice,i) + find(bob,i);
        }
        
        return sum ? -1 : res;
    }
};