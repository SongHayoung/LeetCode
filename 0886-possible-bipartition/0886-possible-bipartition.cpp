class Solution {
    bool helper(vector<int>& group, vector<vector<int>>& edges, int start) {
        queue<int> q;
        q.push(start);
        group[start] = 1;
        while(!q.empty()) {
            auto person = q.front(); q.pop();
            for(auto near : edges[person]) {
                if(group[near] == 0) {
                    group[near] = -group[person];
                    q.push(near);
                } else if(group[near] * group[person] == 1) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n + 1);
        for(auto dislike : dislikes) {
            g[dislike[0]].push_back(dislike[1]);
            g[dislike[1]].push_back(dislike[0]);
        }
        
        vector<int> group(n + 1);
        for(int i = 1; i <= n; i++) {
            if(group[i] == 0)
                if(!helper(group, g, i))
                    return false;
        }
        return true;
    }
};