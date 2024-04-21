
class LRUCache {
    int cap;
    list<int> li;
    unordered_map<int,list<int>::iterator> it;
    unordered_map<int,int> cache;
public:
    LRUCache(int capacity): cap(capacity) {

    }

    int get(int key) {
        if(!cache.count(key)) return -1;
        li.erase(it[key]);
        li.push_front(key);
        it[key] = begin(li);
        return cache[key];
    }

    void put(int key, int value) {
        if(cap == cache.size() and !cache.count(key)) {
            int evict = li.back();
            li.pop_back();
            cache.erase(evict);
            it.erase(evict);
        }
        cache[key] = value;
        if(it.count(key)) {
            li.erase(it[key]);
        }
        li.push_front(key);
        it[key] = begin(li);
        return;cache[key];
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

