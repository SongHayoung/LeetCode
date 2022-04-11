class HitCounter {
    multiset<int> s;
public:
    /** Initialize your data structure here. */
    HitCounter() {}

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        s.insert(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        auto f = s.upper_bound(timestamp - 300);
        auto t = s.upper_bound(timestamp);
        return distance(f, t);
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */