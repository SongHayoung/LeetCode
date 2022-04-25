class SORTracker {
    set<pair<int,string>> s;
    set<pair<int,string>>::iterator it = end(s);
public:
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        auto iit = s.insert({-score, name}).first;
        if(it == end(s) or *iit < *it)
            --it;
    }
    
    string get() {
        return (it++)->second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */