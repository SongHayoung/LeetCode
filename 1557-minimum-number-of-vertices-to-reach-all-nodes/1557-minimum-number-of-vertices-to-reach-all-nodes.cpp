class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> nodes(n);
        for(auto& e : edges) {
            nodes[e[1]] = true;
        }
        vector<int> res;
        for(int i = 0; i < n; i++)
            if(!nodes[i])
                res.push_back(i);
        return res;
    }
};