class Solution {
    vector<int> dp;
    vector<vector<int>> graph;
    int solution(int position) {
        if(dp[position] != -1) return dp[position];
        dp[position] = 0;
        int res = graph[position].empty() ? 0 : 1;
        for(auto next : graph[position]) {
            res &= solution(next);
        }
        return dp[position] = res;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        dp = vector<int>(n, -1);
        dp[destination] = 1;
        graph = vector<vector<int>>(n,vector<int>());
        
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            if(edge[0] == destination) return false;
        }
        
        return solution(source);
    }
};

