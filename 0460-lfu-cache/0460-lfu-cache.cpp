class LFUCache {
    int cap,lo;
    unordered_map<int,pair<int, int>> cache;
    unordered_map<int, list<int>> ord;
    unordered_map<int, list<int>::iterator> it;
public:
    LFUCache(int capacity): cap(capacity), lo(0) {}

    void incr(int key) {
        ord[cache[key].second].erase(it[key]);
        if(ord[cache[key].second].size() == 0) {
            ord.erase(cache[key].second);
            if(lo == cache[key].second) lo++;
        }

        cache[key].second++;
        ord[cache[key].second].push_front(key);
        it[key] = begin(ord[cache[key].second]);
    }

    int get(int key) {
        if(!cache.count(key)) return -1;
        incr(key);
        return cache[key].first;
    }
    void del() {
        int key = *prev(ord[lo].end());
        ord[lo].pop_back();
        if(ord[lo].size() == 0) ord.erase(lo);
        it.erase(key);
        cache.erase(key);
    }

    void put(int key, int value) {
        if(cache.size() == cap and !cache.count(key)) {
            del();
        }
        if(cache.count(key)) {
            cache[key].first = value;
            incr(key);
        } else {
            lo = 1;
            cache[key] = {value, 1};
            ord[1].push_front(key);
            it[key] = begin(ord[cache[key].second]);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
