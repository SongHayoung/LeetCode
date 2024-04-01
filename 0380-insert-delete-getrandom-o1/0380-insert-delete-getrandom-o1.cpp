class RandomizedSet {
    vector<int> buc;
    unordered_map<int, int> cache;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(cache.count(val)) return false;
        cache[val] = buc.size();
        buc.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!cache.count(val)) return false;
        int lst = buc.back();
        buc[cache[val]] = lst;
        cache[lst] = cache[val];
        cache.erase(val);
        buc.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return buc[rand() % buc.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */