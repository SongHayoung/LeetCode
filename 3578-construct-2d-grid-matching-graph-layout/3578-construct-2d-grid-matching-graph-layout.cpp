class Solution {
    vector<vector<int>> build1n(vector<int>& ind, vector<vector<int>>& adj, vector<vector<int>>& e, int n) {
        vector<int> res(n);
        for(int i = 0; i < n; i++) if(ind[i] == 1) res[0] = i;
        unordered_set<int> use{res[0]};
        for(int i = 0; i < n - 1; i++) {
            for(auto& v : adj[res[i]]) if(!use.count(v)) res[i+1] = v;
            use.insert(res[i+1]);
        }
        return {res};
    }
    vector<vector<int>> build2n(vector<int>& ind, vector<vector<int>>& adj, vector<vector<int>>& e, int n) {
        vector<int> res1(n/2), res2(n/2);
        for(int i = 0, find = 0; i < n and !find; i++) if(ind[i] == 2) {
            for(auto& v : adj[i]) {
                if(ind[v] != 2) continue;
                find = 1;
                res1[0] = i, res2[0] = v;
                break;
            }
        }
        unordered_set<int> use{res1[0], res2[0]};
        for(int i = 0; i < n / 2 - 1; i++) {
            for(auto& v : adj[res1[i]]) if(!use.count(v)) res1[i+1] = v;
            for(auto& v : adj[res2[i]]) if(!use.count(v)) res2[i+1] = v;
            use.insert(res1[i+1]);
            use.insert(res2[i+1]);
        }
        return {res1,res2};
    }
    vector<vector<int>> buildnm(vector<int>& ind, vector<vector<int>>& adj, vector<vector<int>>& e, int n) {
        vector<int> head{0};
        for(int i = 0; i < n; i++) if(ind[i] == 2) {
            head[0] = i;
            break;
        }
        unordered_set<int> use{head[0]};
        while(1) {
            int u = head.back();
            for(auto& v : adj[u]) {
                if(use.count(v)) continue;
                if(ind[v] == 2 or ind[v] == 3) {
                    head.push_back(v);
                    break;
                }
            }
            use.insert(head.back());
            if(ind[head.back()] == 2) break;
        }
        int m = head.size();
        n /= m;
        vector<vector<int>> res(n, vector<int>(m));
        res[0] = head;
        for(int i = 1; i < n; i++) {
            for(auto& v : adj[res[i-1][0]]) {
                if(use.count(v)) continue;
                if(ind[v] <= 3) res[i][0] = v;
            }
            for(auto& v : adj[res[i-1][m-1]]) {
                if(use.count(v)) continue;
                if(ind[v] <= 3) res[i][m-1] = v;
            }
            use.insert(res[i][0]);
            use.insert(res[i][m-1]);
        }
        for(int i = 1; i < m - 1; i++) {
            for(auto& v : adj[res[n-1][i-1]]) {
                if(use.count(v)) continue;
                if(ind[v] == 3) res[n-1][i] = v;
            }
            use.insert(res[n-1][i]);
        }
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                int u = res[i-1][j], l = res[i][j-1];
                bool ok = false;
                for(auto& v1 : adj[u]) {
                    if(use.count(v1)) continue;
                    if(ok) break;
                    for(auto& v2 : adj[l]) {
                        if(use.count(v2)) continue;
                        if(v1 != v2) continue;
                        res[i][j] = v1;
                        use.insert(v1);
                        break;
                    }
                }
            }
        }
        return res;
    }
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<int> ind(n);
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ind[u]++, ind[v]++;
        }
        if(edges.size() == n - 1)
            return build1n(ind,adj,edges,n);
        if(n % 2 == 0 and edges.size() == n / 2 + 2 * (n / 2 - 1))
            return build2n(ind,adj,edges,n);
        return buildnm(ind,adj,edges,n);
    }
};