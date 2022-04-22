struct Trie{
    unordered_map<string, Trie*> next;
    int val = -1;
    
    Trie(){}
    bool insert(queue<string>& q, int v) {
        if(q.empty()) { 
            if(val == -1) {
                val = v; return true;
            } else return false;
        } else {
            auto p = q.front(); q.pop();
            if(!next.count(p) and q.empty()) next[p] = new Trie();
            if(next.count(p)) return next[p]->insert(q, v);
            return false;
        }
    }
    int get(queue<string>& q) {
        if(q.empty()) return val;
        else {
            auto p = q.front(); q.pop();
            if(!next.count(p)) return -1;
            return next[p]->get(q);
        }
    }
};
class FileSystem {
    Trie* t;
public:
    FileSystem() {
        t = new Trie();
    }
    
    queue<string> pathQ(string& path) {
        if(path.length() <= 1) return {};
        queue<string> q;
        int i = 1, n = path.length();
        string s;
        while(i < n) {
            if(path[i] == '/') {
                q.push(s);
                s = "";
            } else s.push_back(path[i]);
            i++;
        }
        q.push(s);
        return q;
    }
    
    bool createPath(string path, int value) {
        auto q = pathQ(path);
        
        return t->insert(q,value);
    }
    
    int get(string path) {
        auto q = pathQ(path);
        
        return t->get(q);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */