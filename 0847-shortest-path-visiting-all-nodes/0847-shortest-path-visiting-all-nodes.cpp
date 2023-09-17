class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;
        vector<unordered_set<int>> visit(n);
        //count, group, node
        queue<array<int,3>> q;
        int target = (1<<n) - 1;
        for(int i = 0; i < n; i++) {
            q.push({1, 1<<i, i});
            visit[i].insert(1<<i);
        }
        
        while(!q.empty()) {
            auto [count, group, node] = q.front(); q.pop();
            for(auto next : graph[node]) {
                int nextGroup = group | (1<<next);
                if(visit[next].count(nextGroup)) continue;
                visit[next].insert(nextGroup);
                q.push({count + 1, nextGroup, next});
                if(nextGroup == target) return count;
            }
        }
        return -1;
    }
};