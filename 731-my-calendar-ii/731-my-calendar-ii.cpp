class MyCalendarTwo {
    map<int, int> m;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int cnt = 0;
        for(auto [time, v]: m) {
            cnt += v;
            if(cnt >= 3) {
                m[start]--;
                m[end]++;
                if(!m[start]) m.erase(start);
                if(!m[end]) m.erase(end);
                return false;
            }
            if(time > end) break;
        }
        if(!m[start]) m.erase(start);
        if(!m[end]) m.erase(end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */