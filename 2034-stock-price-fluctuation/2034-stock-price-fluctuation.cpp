class StockPrice {
    unordered_map<int, int> mp;
    int ct = -1, cc = 0;
    priority_queue<pair<int, int>> ma;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> mi;
    
public:
    StockPrice() {}
    
    void update(int timestamp, int price) {
        mp[timestamp] = price;
        ma.push({price, timestamp});
        mi.push({price, timestamp});
        if(ct <= timestamp) {
            ct = timestamp;
            cc = price;
        }
    }
    
    int current() {
        return cc;
    }
    
    int maximum() {
        while(!ma.empty()) {
            auto [price, time] = ma.top();
            if(mp[time] == price) break;
            ma.pop();
        }
        return ma.top().first;
    }
    
    int minimum() {
        while(!mi.empty()) {
            auto [price, time] = mi.top();
            if(mp[time] == price) break;
            mi.pop();
        }
        return mi.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */