class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rind(k + 1), cind(k + 1);
        vector<vector<int>> radj(k+1), cadj(k+1);
        for(auto& r : rowConditions) {
            int v = r[0], u = r[1];
            radj[u].push_back(v);
            rind[v]++;
        }
        for(auto& c : colConditions) {
            int v = c[0], u = c[1];
            cadj[u].push_back(v);
            cind[v]++;
        }
        vector<vector<int>> res(k,vector<int>(k));
        queue<int> r,c;
        vector<int> rat(k+1), cat(k+1);
        for(int i = 1; i <= k; i++) {
            if(!rind[i]) r.push(i);
            if(!cind[i]) c.push(i);
        }
        for(int val = 1; val <= k; val++) {
            if(!r.size() or !c.size()) return {};
            int ru = r.front(); r.pop();
            rat[ru] = k - val;
            for(auto& v : radj[ru]) {
                if(--rind[v] == 0) r.push(v);
            }
            int cu = c.front(); c.pop();
            cat[cu] = k - val;
            for(auto& v : cadj[cu]) {
                if(--cind[v] == 0) c.push(v);
            }
        }
        for(int i = 1; i <= k; i++) {
            res[rat[i]][cat[i]] = i;
        }
        
        return res;
    }
};