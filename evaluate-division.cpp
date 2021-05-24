class Solution {
    double bfs(string from, string to, unordered_map<string, list<pair<string, double>>>& m) {
        unordered_set<string> v;
        queue<pair<string, double>> q;
        q.push({from, 1.0});
        v.insert(from);
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(auto& near : m[p.first]) {
                if(near.first == to) return p.second * near.second;
                if(v.count(near.first)) continue;
                v.insert(near.first);
                q.push({near.first, p.second * near.second});
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        unordered_map<string, list<pair<string, double>>> m;
        vector<double> res;
        for(int i = 0; i < v.size(); i++) {
            m[e[i].front()].push_back({e[i].back(), v[i]});
            m[e[i].back()].push_back({e[i].front(), 1/v[i]});
        }
        for(auto& query : q) {
            res.push_back(bfs(query.front(), query.back(), m));
        }
        return res;
    }
};
