class CombinationIterator {
    vector<int> pos;
    string s;
    bool start = true;
    void posNext() {
        if(pos.back() != s.length() - 1) {
            pos.back()++;
        } else {
            for(int i = pos.size() - 2; i >= 0; i--) {
                if(pos[i] + 1 == pos[i+1]) continue;
                pos[i]++;
                for(int k = i + 1; k < pos.size(); k++) pos[k] = pos[k-1] + 1;
                break;
            }
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) : s(characters){
        pos = vector<int>(combinationLength);
        iota(begin(pos), end(pos), 0);
    }
    
    string next() {
        if(!start) {
            posNext();
        }
        string res = "";
        for(auto& p : pos) res.push_back(s[p]);
        start = false;
        return res;
    }
    
    bool hasNext() {
        if(start) return true;
        return pos[0] != s.length() - pos.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */