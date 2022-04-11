class Solution {
    unordered_map<int, vector<int>> parent;
    unordered_map<int, int> graph;
    bool hasCycle(int start, int target) {
        while(parent.count(start)) {
            start = parent[start][0];
            if(start == target) return true;
        }
        return false;
    }
    int find(int n) {
        if(!graph.count(n)) {
            return graph[n] = n;
        } else return graph[n] == n ? n : graph[n] = find(graph[n]);
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int targetNode = INT_MIN;
        vector<int> res;
        for(auto vec : edges) {
            parent[vec[1]].push_back(vec[0]);
            if(parent[vec[1]].size() == 2) targetNode = vec[1];
            
            int pa = find(vec[0]), pb = find(vec[1]);
            if(pa == pb) {
                res = vec;
            } else graph[pa] = graph[pb] = min(pa,pb);
            
        }
        if(targetNode == INT_MIN) return res;
        if(hasCycle(parent[targetNode][0], targetNode)) {
            return {parent[targetNode][0], targetNode};
        } else {
            return {parent[targetNode][1], targetNode};
        }
    }
};