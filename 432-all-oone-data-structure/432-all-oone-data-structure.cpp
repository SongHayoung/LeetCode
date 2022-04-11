struct KeyWrapper{
    int count;
    unordered_set<string> keys;
};
class AllOne {
    list<KeyWrapper> keyWrappers;
    unordered_map<string, list<KeyWrapper>::iterator> mp;
    
    list<KeyWrapper>::iterator insertNext(KeyWrapper wrapper, list<KeyWrapper>::iterator it) {
        auto nxt = next(it);
        if(it == end(keyWrappers)) {
            keyWrappers.push_back(wrapper);
            return prev(end(keyWrappers));
        }
        return keyWrappers.insert(nxt, wrapper);
    }
public:
    AllOne() {}
    
    void inc(string key) {
        if(!mp.count(key)) {
            if(keyWrappers.empty() or keyWrappers.front().count != 1) {
                keyWrappers.push_front(KeyWrapper{1,{key}});
            } else {
                keyWrappers.front().keys.insert(key);
            }
            mp[key] = keyWrappers.begin();
        } else {
            auto cur = mp[key];
            auto nxt = next(cur);
            if(nxt == end(keyWrappers) or (*nxt).count != cur->count + 1) {
                auto newIt = insertNext(KeyWrapper{cur->count + 1, {key}}, cur);
                mp[key] = newIt;
            } else {
                nxt->keys.insert(key);
                mp[key] = nxt;
            }
            cur->keys.erase(key);
            if(cur->keys.empty())
                keyWrappers.erase(cur);
        }
    }
    
    void dec(string key) {
        if(!mp.count(key)) return;
        
        auto cur = mp[key];
        cur->keys.erase(key);

        if(cur == begin(keyWrappers) or (*prev(cur)).count != cur->count - 1) {
            if(cur == begin(keyWrappers)) {
                if(cur->count == 1) mp.erase(key);
                else {
                    keyWrappers.push_front(KeyWrapper{cur->count - 1, {key}});
                    mp[key] = keyWrappers.begin();
                }
            } else {
                auto prv = prev(cur);
                auto newIt = insertNext(KeyWrapper{cur->count - 1, {key}}, prv);
                mp[key] = newIt;
            }
        } else {
            auto prv = prev(cur);
            prv->keys.insert(key);
            mp[key] = prv;
        }
        
        if(cur->keys.empty())
            keyWrappers.erase(cur);
    }
    
    string getMaxKey() {
        if(keyWrappers.empty()) return"";
        return *keyWrappers.back().keys.begin();
    }
    
    string getMinKey() {
        if(keyWrappers.empty()) return"";
        return *keyWrappers.front().keys.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */