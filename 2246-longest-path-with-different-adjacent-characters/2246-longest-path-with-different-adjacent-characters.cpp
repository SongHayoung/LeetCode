class Solution {
    int res = 0;
    vector<vector<int>> g;

    int helper(int u, string& s) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& v : g[u]) {
            int path = helper(v,s);
            if(s[v] != s[u]) {
                pq.push(path);
                if(pq.size() > 2) pq.pop();
            }
        }

        while(pq.size() < 2) pq.push(0);

        int path1 = pq.top(); pq.pop();
        int path2 = pq.top(); pq.pop();

        res = max(res, path1 + path2 + 1);

        return path2 + 1;
    }
public:
    int longestPath(vector<int>& p, string s) {
        int n = p.size(), root = -1;
        g = vector<vector<int>>(n);

        for(int i = 0; i < n; i++) {
            if(p[i] == -1) root = i;
            else g[p[i]].push_back(i);
        }

        return max(helper(root, s), res);
    }
};
