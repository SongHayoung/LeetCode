class MyHashMap {
private:
    vector<map<int, int>> myHashMap;
    
    int hash(int key) {
        return key % 31;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        myHashMap = vector<map<int, int>> (31, map<int,int>());
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        myHashMap[index][key] = value;
        return;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        if(myHashMap[index].count(key))
            return myHashMap[index][key];
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        if(myHashMap[index].count(key))
            myHashMap[index][key] = -1;
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
