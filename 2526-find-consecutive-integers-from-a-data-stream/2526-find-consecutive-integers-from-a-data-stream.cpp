class DataStream {
    int v,ma,c;
public:
    DataStream(int value, int k) : v(value), ma(k), c(0) {}

    bool consec(int num) {
        if(v == num) c = min(c + 1, ma);
        else c = 0;
        return c == ma;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */