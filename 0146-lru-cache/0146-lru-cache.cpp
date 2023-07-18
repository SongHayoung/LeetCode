class LRUCache {
private:
    map<int, list<pair<int,int>>::iterator> m;
    list<pair<int, int>> l;
    int c;

    void moveFront(list<pair<int, int>>& li, list<pair<int,int>>::iterator it) {
        if(it != begin(li)) {
            li.splice(li.begin(), li, it, next(it));
        }
    }
    
    void insert(int key, int value) {
        l.push_front({key, value});
        m[key] = l.begin();
        if(l.size() > c) {
            balance(l.back().first);
        }
    }
    
    void balance(int key) {
        m.erase(key);
        l.pop_back();
    }
public:
    LRUCache(int capacity) : c(capacity) {}

    int get(int key) {
        if(!m.count(key)) return -1;
        int res = m[key]->second;
        moveFront(l, m[key]);

        return res;
    }

    void put(int key, int value) {
        if(!m.count(key)) {
            insert(key, value);
        } else {
            m[key]->second = value;
            moveFront(l, m[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */