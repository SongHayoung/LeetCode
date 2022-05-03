class RandomizedCollection {
    long long expire = LLONG_MIN;
    unordered_map<long long, vector<int>> mp;
    vector<long long> arr;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        mp[val].push_back(arr.size());
        arr.push_back(val);
        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        if(mp[val].empty()) return false;
        
        int idx = mp[val].back();
        arr[idx] = expire;
        mp[val].pop_back();
        return true;
    }
    
    int getRandom() {
        while(arr.back() == expire) arr.pop_back();
        long long res = expire;
        while(res == expire) {
            int r = rand() % arr.size();
            res = arr[r];
        }
        return res;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */