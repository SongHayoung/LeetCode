class MyCalendar {
    map<int, int> m;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto nxt = m.upper_bound(start);
        if(nxt != m.end() and nxt->first < end) {
            return false;
        }
        if(nxt != m.begin() and (--nxt)->second > start) {
            return false;
        }
        m[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */