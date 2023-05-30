#define BUCKET 31
class MyHashSet {
    set<int> s[BUCKET];
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        s[key % BUCKET].insert(key);
    }
    
    void remove(int key) {
        s[key % BUCKET].erase(key);
    }
    
    bool contains(int key) {
        return s[key % BUCKET].count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */