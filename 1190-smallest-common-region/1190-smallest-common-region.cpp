class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, int> idmp;
        unordered_map<string, string> parmp;
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> level;
        int id = 1;
        for(auto& rs : regions) {
            for(int i = 1; i < rs.size(); i++) {
                auto par = rs[0], child = rs[i];
                if(!idmp.count(par)) idmp[par] = id++;
                if(!idmp.count(child)) idmp[child] = id++;
                parmp[child] = par;
                adj[par].push_back(child);
            }
        }
        string root = "";
        for(auto [r, id] : idmp) {
            if(parmp.count(r)) continue;
            root = r;
        }
        queue<string> q;
        q.push(root);
        level[root] = 0;
        int lvl = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto u = q.front(); q.pop();
                for(auto& v : adj[u]) {
                    q.push(v);
                    level[v] = lvl;
                }
            }
            lvl++;
        }
        while(region1 != region2) {
            if(level[region1] > level[region2]) region1 = parmp[region1];
            else if(level[region1] < level[region2]) region2 = parmp[region2];
            else {
                region1 = parmp[region1];
                region2 = parmp[region2];
            }
        }
        return region1;
    }
};