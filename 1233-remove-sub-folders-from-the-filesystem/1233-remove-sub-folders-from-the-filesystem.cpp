struct Trie {
    unordered_map<string, Trie*> next;
    bool eof = false;
    string path = "";
    Trie() {};
    
    string parse(string& s, int& p) {
        string res = "";
        while(s.length() > p and s[p] != '/') {
            res.push_back(s[p++]);
        }
        p++;
        return res;
    }
    void insert(string& s, int& p) {
        if(p >= s.length()) eof = true, path = s;
        else {
            auto token = parse(s,p);
            if(!next.count(token)) next[token] = new Trie();
            next[token]->insert(s, p);
        }
    }
    
    void query(vector<string>& res) {
        if(eof) res.push_back(path);
        else {
            for(auto& [_, t] : next)
                t->query(res);
        }
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* t = new Trie();
        for(auto& f : folder) {
            int p = 0;
            t->insert(f,p);
        }
        vector<string> res;
        t->query(res);
        
        return res;
    }
};