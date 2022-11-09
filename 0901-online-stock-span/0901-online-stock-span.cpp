class StockSpanner {
    vector<pair<int, int>> v;
public:
    StockSpanner() {

    }

    int next(int price) {
        int day = 1, pos = v.size() - 1;
        while(pos >= 0) {
            if(v[pos].first > price) break;
            day += v[pos].second;
            pos -= v[pos].second;
        }
        v.push_back({price,day});
        return day;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */