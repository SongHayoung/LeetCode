class Solution {
    unordered_map<string, vector<string>> g;
    unordered_set<string> c;
    int len = INT_MAX;
    vector<vector<string>> res;
    bool similar(string& s1, string& s2) { //o(k)
        int diff = 0;
        for(int i = 0; i < s1.length() and diff < 2; i++) {
            if(s1[i] != s2[i]) diff++;
        }
        return diff == 1;
    }
    
    void buildG(vector<string>& w, string& begin) { //o(n^2)
        for(int i = 0; i < w.size(); i++) {
            for(int j = i + 1; j < w.size(); j++) {
                if(similar(w[i], w[j])) {
                    g[w[i]].push_back(w[j]);
                    g[w[j]].push_back(w[i]);
                }
            }
        }
        if(!g.count(begin)) {
            for(int i = 0; i < w.size(); i++) {
                if(similar(begin,w[i])) 
                    g[begin].push_back(w[i]);
            }
        }
    }
    
    void bfs(string& st, string& t) {
        queue<vector<string>> q;
        unordered_set<string> v{st};
        q.push({st});
        while(res.empty()) {
            int sz = q.size();
            unordered_set<string> lv;
            while(sz--) {
                auto vec = q.front(); q.pop();
                for(auto nxt : g[vec.back()]) {
                    if(v.count(nxt)) continue;
                    if(nxt == t) {
                        vec.push_back(nxt);
                        res.push_back(vec);
                        break;
                    } else {
                        lv.insert(nxt);
                        vec.push_back(nxt);
                        q.push(vec);
                        vec.pop_back();
                    }
                }
            }
            v.insert(lv.begin(),lv.end());
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        buildG(wordList, beginWord);
        if(!g.count(endWord)) return res;
        vector<string> tmp{beginWord};
        c.insert(beginWord);
        bfs(beginWord, endWord);
        
        return res;
    }
};