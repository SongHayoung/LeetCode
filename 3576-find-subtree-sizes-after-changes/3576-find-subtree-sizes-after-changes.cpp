class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        vector<int> P = parent;
        for(int i = 1; i < parent.size(); i++) {
            int p = parent[i];
            while(p != -1 and s[p] != s[i]) p = parent[p];
            if(p != -1) P[i] = p;
        }
        vector<int> res(parent.size(), 1), deg(parent.size());
        queue<int> q;
        for(int i = 1; i < parent.size(); i++) deg[P[i]]++;
        for(int i = 1; i < parent.size(); i++) if(!deg[i]) q.push(i);
        while(q.size()) {
            int u = q.front(); q.pop();
            res[P[u]] += res[u];
            if(--deg[P[u]] == 0 and P[u]) q.push(P[u]);
        }
        return res;
    }
};
