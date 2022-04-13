class MyCalendarThree {
    map<int, int> m;
    int recaculate = 0;
    int lastLeft=-1, lastRight=-1;
    int most = 0;
    
    void calc() {
        int cnt = 0;
        bool findLeft = false, findRight = false;
        for(auto [k, v]: m) {
            if(v < 0 and cnt == most and !findRight) {
                findRight = true;
                findLeft = false;
                lastRight = k;
            }
            
            cnt += v;
            
            if(cnt > most and !findLeft) {
                most = cnt;
                lastLeft = k;
                findLeft = true;
                findRight = false;
            }
        }
    }
    
public:
    MyCalendarThree() {}
    bool inrange(int n) {
        return (lastLeft <= n and n <= lastRight);
    }
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        if(recaculate == 0) {
            calc();
        } else if(inrange(start) or inrange(end)) {
            recaculate++;
        } else {
            recaculate--;
        }
        
        return most;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */