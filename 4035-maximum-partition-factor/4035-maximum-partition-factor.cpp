class Solution {
    int dis(vector<int>& A, vector<int>& B) {
        return abs(A[0] - B[0]) + abs(A[1] - B[1]);
    }
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int u, int par) {
        for(auto& v : adj[u]) {
            if(vis[v] == vis[u]) return true;
            if(vis[v] == -1) {
                vis[v] = !vis[u];
                if(dfs(adj,vis,v,u)) return true;
            }
            
        }
        return false;
    }
    bool helper(vector<vector<int>>& A, int d) {
        vector<vector<int>> adj(A.size());
        for(int i = 0; i < A.size(); i++) {
            for(int j = i + 1; j < A.size(); j++) {
                if(dis(A[i], A[j]) < d) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(A.size(), -1);
        for(int i = 0; i < A.size(); i++) {
            if(vis[i] != -1) continue;
            vis[i] = 0;
            if(dfs(adj,vis, i,-1)) return false;
        }
        return true;
    }
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        if(points.size() == 2) return 0;
        int l = 0, r = 0, res = 0;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                r = max(r, dis(points[i], points[j]));
            }
        }
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(points, m);
            if(ok) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
};
