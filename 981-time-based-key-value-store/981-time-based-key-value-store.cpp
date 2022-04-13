class TimeMap {
    unordered_map<string, map<int, string>> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto res = m[key].upper_bound(timestamp);
        return res == m[key].begin() ? "" : prev(res)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */