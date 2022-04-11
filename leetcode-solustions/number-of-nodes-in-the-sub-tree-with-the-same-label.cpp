class Solution {
    void add(int node, vector<list<int>>& edge, unordered_map<char,int>& m, string& s, vector<int>& res) {
        if(!res[node]) {
            res[node] = 1;
            for(auto endPoint : edge[node]) {
                unordered_map<char,int> nm;
                add(endPoint, edge, nm, s, res);
                for(auto& entity : nm) {
                    m[entity.first] += entity.second;
                }
            }
            res[node] = ++m[s[node]];
        }
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<list<int>> sortedEdge(n, list<int>()), parent(n, list<int>());
        vector<int> res(n);
        unordered_map<char, int> m;
        for(auto& edge : edges) {
            sortedEdge[edge.front()].push_back(edge.back());
            sortedEdge[edge.back()].push_back(edge.front());
        }
        add(0, sortedEdge, m, labels, res);
        return res;
    }
};
