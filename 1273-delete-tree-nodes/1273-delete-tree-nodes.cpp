class Solution {
    vector<vector<int>> g;
    pair<int, int> helper(int u, vector<int>& va) {
        int sum = 0, child = 0;
        for(auto& v : g[u]) {
            auto [s, c] = helper(v, va);
            sum += s;
            child += c;
        }
        
        if(sum + va[u] == 0)
            return {0, 0};
        else return {sum + va[u], child + 1};
    }
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        g = vector<vector<int>>(nodes);
        int root;
        for(int i = 0; i < nodes; i++)
            if(parent[i] != -1)
                g[parent[i]].push_back(i);
            else root = i;
        return helper(root, value).second;
    }
};