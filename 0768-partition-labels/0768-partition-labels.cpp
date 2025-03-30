class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> m;
        vector<int> res{-1};
        for(int i = 0; i < s.length(); i++) {
            m[s[i]].push_back(i);
        }
        while(!m.empty()) {
            char c;
            int p(INT_MAX);
            for(auto& e : m) {
                if(e.second.front() < p) {
                    c = e.first;
                    p = e.second.front();
                }
            }
            int val = m[c].back();
            m.erase(c);
            bool removed = true;
            while(removed) {
                removed = false;
                queue<char> q;
                for(auto& e : m) {
                    if(e.second.front() < val) {
                        val = max(val, e.second.back());
                        q.push(e.first);
                    }
                }
                if(q.size()) {
                    removed = true;
                    while(!q.empty()) {
                        m.erase(q.front());
                        q.pop();
                    }
                }
            }
            res.push_back(val);
        }
        int sz = res.size();
        for(int i = sz - 1; i >= 1; i--) {
            res[i] = res[i] - res[i - 1];
        }
        return vector<int>(res.begin() + 1, res.end());
    }
};