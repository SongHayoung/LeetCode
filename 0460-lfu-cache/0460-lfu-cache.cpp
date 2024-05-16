class LFUCache {
    unordered_map<int, pair<int,int>> vmp;
    unordered_map<int, list<int>::iterator> imp;
    unordered_map<int, list<int>> mp;
    int c,lo;
public:
    LFUCache(int capacity): c(capacity), lo(1) {}
    void promote(int key) {
        int freq = vmp[key].first;
        {
            mp[freq].erase(imp[key]);
            imp.erase(key);
            if(lo == freq and mp[lo].size() == 0) lo++;
            if(mp[lo].size() == 0) mp.erase(lo);
        }
        
        vmp[key].first++;
        mp[freq+1].push_front(key);
        imp[key] = begin(mp[freq+1]);
        
    }
    void expire() {
        int x = mp[lo].back(); mp[lo].pop_back();
        imp.erase(x);
        vmp.erase(x);
        if(mp[lo].size() == 0) mp.erase(lo);
    }
    int get(int key) {
        if(!vmp.count(key)) return -1;
        promote(key);
        return vmp[key].second;
    }
    
    void put(int key, int value) {
        if(!vmp.count(key) and vmp.size() == c) {
            expire();
        }
        if(vmp.count(key)) {
            vmp[key].second = value;
            promote(key);
        } else {
            vmp[key] = {1,value};
            mp[1].push_front(key);
            imp[key] = begin(mp[1]);
            lo = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */