struct Trie {
    unordered_map<string, Trie*> next;
    int idx;
    Trie(): idx(-1) {};

    string parse(string& s, int& p) {
        string res = "";
        while(s.length() > p and s[p] != '/') {
            res.push_back(s[p++]);
        }
        p++;
        return res;
    }
    void insert(string& s, int& p, int now) {
        if(idx != -1) return;
        if(p >= s.length()) idx = now;
        else {
            auto token = parse(s,p);
            if(!next.count(token)) next[token] = new Trie();
            next[token]->insert(s, p, now);
        }
    }

    void query(vector<string>& res, vector<string>& A) {
        if(idx != -1) res.push_back(A[idx]);
        else {
            for(auto& [_, t] : next)
                t->query(res,A);
        }
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* t = new Trie();
        for(int i = 0; i < folder.size(); i++) {
            int p = 0;
            t->insert(folder[i],p, i);
        }
        vector<string> res;
        t->query(res,folder);

        return res;
    }
};