class ExamRoom {
    int l;
    set<int> s;
public:
    ExamRoom(int n):l(n-1) {}

    int seat() {
        if(s.empty()) {
            s.insert(0);
            return 0;
        } else if(s.size() == 1) {
            int n = *s.begin();
            if(n == 0) {
                s.insert(l);
                return l;
            } else if(n == l) {
                s.insert(0);
                return 0;
            } else {
                if(n > l - n) {
                    s.insert(0); return 0;
                } else {
                    s.insert(l); return l;
                }
            }
        } else {
            int left, right, dis = INT_MIN;
            for(auto i = s.begin(), j = next(s.begin()); j != s.end(); i++,j++) {
                if((*j - *i) / 2 > dis) {
                    dis = (*j - *i) / 2;
                    left = *i; right = *j;
                }
            }
            if(!s.count(0)) {
                int ldis = *s.begin();
                if(ldis >= dis) {
                    dis = ldis;
                    left = 0; right = 0;
                }
            }
            if(!s.count(l)) {
                int ldis = l - *prev(s.end());
                if(ldis > dis) {
                    left = l, right = l;
                }
            }
            
            s.insert(left + (right - left)/2);
            
            return left + (right - left)/2;
        }
    }

    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */