class Solution {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> from;
    void dfs(vector<string>& A, string& u, string& g) {
        A.push_back(u);
        if(u == g) res.push_back(A);
        else {
            for(auto& v : from[u]) {
                dfs(A,v,g);
            }
        }
        A.pop_back();
    }
public:
    vector<vector<string>> findLadders(string s, string e, vector<string>& w) {
        unordered_set<string> us(begin(w), end(w));
        if(s == e) return {{s}};
        if(!us.count(e)) return {};
        from = {};
        queue<string> q;
        q.push(s);
        from[s] = {""};
        while(q.size() and !from.count(e)) {
            int qsz = q.size();
            unordered_map<string,vector<string>> now;
            while(qsz--) {
                auto u = q.front(); q.pop();
                string str = u;
                for(int i = 0; i < u.length(); i++) {
                    char ori = u[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        u[i] = ch;
                        if(!us.count(u)) continue;
                        if(from.count(u)) continue;
                        now[u].push_back(str);
                    }
                    u[i] = ori;
                }
            }
            for(auto& [k,v] : now) {
                from[k] = v;
                q.push(k);
            }
        }
        if(!from.count(e)) return {};
        res = {};
        vector<string> path;
        dfs(path,e,s);
        for(auto& w : res) {
            reverse(begin(w), end(w));
        }
        return res;
    }
};