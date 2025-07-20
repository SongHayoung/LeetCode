struct Trie {
    string path;
    map<string, Trie*> next;
    bool del;
    Trie(string name = "") : path(name), del(false) {};

    void insert(vector<string>& paths, int pos = 0) {
        if(pos == paths.size()) return;
        if(!next.count(paths[pos])) next[paths[pos]] = new Trie(paths[pos]);
        next[paths[pos]]->insert(paths, pos + 1);
    }

    string dup(unordered_map<string, Trie*>& seen) {
        string sub = "";
        for(auto& [_, n] : next) {
            sub += n->dup(seen);
        }
        if(sub.length()) {
            if(seen.count(sub)) seen[sub]->del = this->del = true;
            seen[sub] = this;
        }
    
        return "(" + path + sub +")";
    }

    void query(vector<vector<string>>& res, vector<string>& p) {
        if(del) return;
        if(!p.empty()) res.push_back(p);
        for(auto [sub, ntr] : next) {
            p.push_back(sub);
            ntr->query(res,p);
            p.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        vector<vector<string>> res;
        Trie* tr = new Trie();
        for(auto& p : paths)
            tr->insert(p);
        tr->dup(unordered_map<string, Trie*>() = {});
        tr->query(res, vector<string>() = {});
        return res;
    }
};