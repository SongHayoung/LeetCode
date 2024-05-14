class MKAverage {
    multiset<int> lo;
    multiset<int> hi;
    multiset<int> mid;
    long long sum,m,k;
    deque<int> dq;
public:
    MKAverage(int m, int k):sum(0), m(m), k(k) {}
    
    void addElement(int num) {
        dq.push_back(num);
        if(dq.size() > m) {
            int x = dq.front(); dq.pop_front();
            if(lo.count(x)) lo.erase(lo.find(x));
            else if(hi.count(x)) hi.erase(hi.find(x));
            else {
                mid.erase(mid.find(x));
                sum -= x;
            }
        }
        if(lo.size() < k) {
            lo.insert(num);
        } else if(hi.size() < k) {
            hi.insert(num);
        } else {
            mid.insert(num);
            sum += num;
        }
        while(lo.size() > k) {
            int x = *prev(end(lo));
            mid.insert(x);
            sum += x;
            lo.erase(prev(end(lo)));
        }
        while(hi.size() > k) {
            int x = *begin(hi);
            mid.insert(x);
            sum += x;
            hi.erase(begin(hi));
        }
        while(mid.size()) {
            if(lo.size() and *begin(mid) < *prev(end(lo))) {
                int x = *begin(mid); mid.erase(begin(mid));
                int y = *prev(end(lo)); lo.erase(prev(end(lo)));
                sum = sum - x + y;
                mid.insert(y);
                lo.insert(x);
            } else if(hi.size() and *prev(end(mid)) > *begin(hi)) {
                int x = *prev(end(mid)); mid.erase(prev(end(mid)));
                 int y = *begin(hi); hi.erase(begin(hi));
                sum = sum - x + y;
                mid.insert(y);
                hi.insert(x);
            } else break;
        }
        
    }
    
    int calculateMKAverage() {
        if(lo.size() + hi.size() + mid.size() < m) return -1;
        if(mid.size() == 0) return 0;
        return 1. * sum / mid.size();
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */